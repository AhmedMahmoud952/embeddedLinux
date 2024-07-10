#include <iostream>

int main() {
    float numbers[3] = {0};
    for (int i = 0; i < 3; i++)
    {
       std::cout << "Enter number " << i << ": ";
       std::cin >> numbers[i];
    }
    int max =   std::max(numbers[0], std::max(numbers[1],numbers[3]));
    std::cout << "the largest number is :"<< max << std::endl;
    

}
