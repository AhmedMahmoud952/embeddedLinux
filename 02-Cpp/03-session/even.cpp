#include <iostream>

int main(int argc, const char** argv) {
 
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Even numbers are: " << std::endl;
    for(auto member : array) {
        if (member%2 == 0) 
        {
            std::cout << member << ", " << std::flush;
        }
    }
    std::cout << std::endl << "Odd numbers are: " << std::endl;
    for(auto member : array)
    {
        if (member%2 != 0)
        {
            std::cout << member << ", " << std::flush;
        }
    }

    return 0;
}