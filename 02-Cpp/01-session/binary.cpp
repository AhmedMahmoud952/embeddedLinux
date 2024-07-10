#include <iostream>
#include <iomanip>
#include <bitset>
int main() {
    int num = 0;
    std::bitset<8> bits;
    
    // get input from user and convert to bitset
    std::cout << "Enter a Number: ";
    std::cin >> num;

    // print binary representation of the number using bitset
    std::bitset<8> binary (num);
    std::cout << binary << std::endl;

    // get binary input from user and convert to bitset
    std::cout << "Enter a binary number: ";
    std::cin >> bits;

    // convert bitset to decimal
    unsigned long decimal_value = bits.to_ulong(); 
    std::cout << decimal_value << std::endl; 
}
