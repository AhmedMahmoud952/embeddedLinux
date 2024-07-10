#include <iostream>

int main() {
    
    char vowels[] = "aeoui";
    char entry;
    std::cout << "Enter a character: ";
    std::cin >> entry;
    entry = char(tolower(entry));
    for (auto car: vowels)
    {
        if (car == entry)
        {
            std::cout << "character is vowel" << std::endl;
            return 0;
        }
    }
        std::cout << "character is not vowel" << std::endl;
}
