#include <iostream>

class arr
{
public:
  arr(int size, int* values);
  bool isAllEven();
  bool iseven(int index);
  ~arr();

private:
  int size = 0;
  int* start = nullptr;
};

arr::arr(int size, int* values): size(size)
{
  std::cout << "Array created with size: " << size << std::endl;
  start = new int[size];
  for (int i = 0; i < size; i++)
  {
    this->start[i] = values[i];
  }
  
}

bool arr::isAllEven()
{
  for (int i = 0; i < this->size; i++)
  {
    if (this->start[i] % 2 != 0)
    {
      return false;
    }
  }
  return true;
}

bool arr::iseven(int index)
{
  if(index < (this->size)){
    if(this->start[index] % 2 == 0) return true;
    else return false;
  }
  else{
    return false;
  }
}

arr::~arr()
{
  std::cout << "Array destroyed." << std::endl;
  delete[] this->start;
  this->start = nullptr;
}

int main()
{
  int arr_size = 5;
  int arr_data[] = {4, 2, 5, 4, 6};
  int arr_data2[] = {4, 2, 18, 4, 6};
  arr my_array(arr_size, arr_data);
  arr my_array1(arr_size, arr_data2);
  std::cout << "Is array even? " << (my_array.isAllEven()? "Yes" : "No") << std::endl;
  std::cout << "Is array even? " << (my_array.iseven(2)? "Yes" : "No") << std::endl;
  std::cout << "Is array even? " << (my_array.iseven(3)? "Yes" : "No") << std::endl;
  std::cout << "Is array even? " << (my_array1.isAllEven()? "Yes" : "No") << std::endl;
  std::cout << "Is array even? " << (my_array1.iseven(2)? "Yes" : "No") << std::endl;
  

  return 0;
}