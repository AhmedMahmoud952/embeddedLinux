#include <iostream>

int main() {
    int num = 0;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::string numbers = std::to_string(num);
    int sum = 0;
    for (auto digit : numbers) {
        sum += std::stoi(std::string(1,digit));
    }
    std::cout << "The summtion is : " << sum << std::endl;

}
