#include <iostream>

class mystring
{
public:
  mystring(const char *str_obj)
  {
    this->size = mystr_len(str_obj);
    this->object = new char[size + 1]; //+1 because of null operator
    copy_string(str_obj);
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
    delete this;
  }
  ~mystring()
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
};




int main()
{
  mystring name("ahmed");
  name.print();
  std::cout << name.length() << std::endl;
  name.clear();
  // name.print();                             //Error instance is deleted
  // std::cout << name.length() << std::endl;  //Error instance is deleted
  return 0;
}