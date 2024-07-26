#include <iostream>

int main(int argc, const char** argv) {

    float number = 0;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> number;

    std::cout << "number Square: " << [number]()->float {return number*number; }() <<std::endl;

    return 0;
}