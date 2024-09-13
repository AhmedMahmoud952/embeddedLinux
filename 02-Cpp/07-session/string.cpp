#include <iostream>

class str
{
public:
  str(): size(0),object(nullptr) {}
  str(const char *str_obj)
  {
    this->size = mystr_len(str_obj);
    this->object = new char[size + 1]; //+1 because of null operator
    copy_string(str_obj);
  }

  // deep copy constructor
  str(const str &copy)
  {
    this->size = copy.size;
    this->object = new char[this->size + 1];
    copy_string(copy.object);
  }

  // overloaded assignment copy operator
  str &operator=(const str &copy){
    if (&copy != this)
    {
      this->size = copy.size;
      if (this->object)
      {
        delete[] this->object; //deallocate memory
      }
      this->object = new char[this->size + 1];
      copy_string(copy.object);
    }
    return *this;
  }

  // move constructor
  str(str &&expired): size(expired.size), object(expired.object)
  {
    expired.size = 0;
    expired.object = nullptr; //set pointer to null to avoid dangling pointer
  }

  // overloaded assignment move operator
  str &operator=(str &&expired)
  {
    if (this != &expired)
    {
      this->size = expired.size;
      expired.size = 0;
      if (this->object)
      {
        delete[] this->object;
      }
      this->object = expired.object;
      expired.object = nullptr; //set pointer to null to avoid dangling pointer
    }
    return *this;
  } 

  // overloaded [] operator
  char &operator[](int index)
  {
    if (index >= this->size)
    {
      std::cerr << "Error: index out of range" << std::endl;
      return this->object[0];
    }
    return this->object[index];
  }

  // overloaded [] operator for const strings
  char &operator[](int index) const
  {
    if (index >= this->size)
    {
      std::cerr << "Error: index out of range" << std::endl;
      return this->object[0];
    }
    return this->object[index];
  }

  // overloaded + operator
  str operator + (const str &other){
    int new_size = this->size + other.size;
    char* temp = new char[new_size];
    conc_string(temp,*this,other);
    str result(temp);
    delete[] temp;
    temp = nullptr;
    return result;
  }

  // overloaded == operator
  bool operator == (const str &other)
  {
    if (this->size == other.size)
    {
      for (int i= 0; i < this->size; i++)
      {
        if (this->object[i] != other.object[i])
        {
          return false;
        }
      }
      return true;
    }
    return false;
  }

  // append to the end of the string
  void append(const str &str_obj){
    
    int new_size = this->size + str_obj.size;
    char *temp = new char[new_size];
    conc_string(temp, *this, str_obj);
    if (this->object)
    {
      delete[] this->object;
    }
    this->size = new_size;
    this->object = temp;
  }

  // get a sub string from a string
  str substr(int start, int length)
  {
    if (start < 0 || start >= this->size || length < 0 || start + length > this->size)
    {
      std::cerr << "Error: Invalid substring range" << std::endl;
      return str();
    }
    char *temp = new char[length + 1];
    for (int i = 0; i < length; i++)
    {
      temp[i] = this->object[start + i];
    } 
    temp[length] = '\0'; 
    str result(temp);
    delete[] temp;
    temp = nullptr;
    return result;
  }

  // find the first position of the sended character
  int find(const char searched_char)
  {
    for (int i = 0; i < this->size; i++)
    {
      if (this->object[i] == searched_char)
      {
        return i;
      }
    }
    return -1; //character not found
  }
  void print(){
    for (int i = 0; i < this->size; i++)
    {
      std::cout << object[i] <<std::flush;
    }
    std::cout << std::endl;
  }

  int length(){
    return this->size;
  }

  void clear(){
    delete[] this->object; //deallocate memory
    this->object = nullptr; //set pointer to null to avoid dangling pointer
    this->size = 0; //set size to 0 to avoid accessing deallocated memory in destructor (undefined behavior)
  }
  ~str()
  {
    clear();
  }
private:
  char *object =nullptr;
  int size = 0;

  int mystr_len(const char *string){
    int len = 0;
    while(string[len]!= '\0'){
      len++;
    }
    return len;
  }

  void copy_string(const char *str_obj){
    for (int i = 0; i < this->size; i++)
    {
      object[i] = str_obj[i];
    }
    object[this->size] = '\0';
  }

  void conc_string(char *temp,const str &first, const str &second)
  {
    for (int i = 0; i < first.size; i++){
      temp[i] = first.object[i];
    }
    for (int i = 0; i < second.size; i++){
      temp[i + this->size] = second.object[i];
    }
    temp[first.size + second.size] = '\0';
  }
};




int main()
{


  

  return 0;
}