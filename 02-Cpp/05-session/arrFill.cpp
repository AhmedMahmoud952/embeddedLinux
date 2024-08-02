#include <iostream>
#include <numeric>

int main()
{
  int size = 9991;
  int arr[size];
  std::iota(arr,arr+size,10);
  
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
    if(i%25 == 24){std::cout << std::endl;}
  }
  return 0;
}