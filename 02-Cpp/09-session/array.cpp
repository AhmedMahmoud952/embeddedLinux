#include <iostream>
#include <array>
#include <string>
#include <cstddef>

void new_section(std::string section_name){
    std::cout << "------------------------------------"<< std::endl;
    std::cout << "New Section: " << section_name << std::endl;
    std::cout << "------------------------------------"<< std::endl;
}


int main()
{
    std::array<int,5> myarray = {1,2,3,4,5};
    for(auto var : myarray)
    {
        std::cout << var << " " << std::flush;
    }
    std::cout << std::endl;
    new_section("Element Access");
    // std::cout << myarray << std::endl; //ERORR
    std::cout << myarray.front() << std::endl;
    std::cout << myarray.back() << std::endl;
    // std::cout << myarray[7] << std::endl;  //Acess a garbage value 
    // std::cout << myarray.at(7) << std::endl; //Throws an exception
    std::cout << myarray.at(4) << std::endl; 
    std::cout << &myarray << " && " << myarray.data() << std::endl; //Pointer to first element
    
    new_section("Itarators");
    std::cout << "const or not: " <<  myarray.begin() << ", always return const: " <<  myarray.cbegin() << std::endl;
    std::cout << "const or not: " <<  myarray.end() << ", always return const: " <<  myarray.cend() << std::endl; //Retrun the postion after the last element
    std::cout << "array.cend() - 1 : " <<*(myarray.cend()-1) << std::endl;
    std::cout << "array.rbegin() : " <<*(myarray.crbegin()) << std::endl;

    new_section("capacity");
    // no difference between size and max_size in arrays
    std::cout << "size: " << myarray.size() << std::endl;
    std::cout << "max_size: " << myarray.max_size() << std::endl;
    std::cout << "empty: " << std::boolalpha << myarray.empty() << std::endl; //checking if the array is empty

    new_section("opertations");
    myarray.fill(0);
    for(auto var : myarray)
    {
        std::cout << var << " " << std::flush;
    }
    std::cout << std::endl;

    

}