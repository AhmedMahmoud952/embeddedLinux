#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setw(9) <<" Ascii " << std::endl;
        std::cout << "+--------+---------+" <<std::endl;
    for (int i = 0; i < 128; i++) {
        std::cout << "|" << std::setw(5) << i << std::setw(4) << "|" 
            << std::setw(5) <<char(i) << std::setw(5)<<"|"<<std::endl;
        std::cout << "+--------+---------+" <<std::endl;
    }

}
