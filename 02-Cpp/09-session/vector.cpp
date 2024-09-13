#include <iostream>
#include <vector>
#include <string>


void new_section(std::string section_name){
    std::cout << "------------------------------------"<< std::endl;
    std::cout << "New Section: " << section_name << std::endl;
    std::cout << "------------------------------------"<< std::endl;
}

// template<typename T>
// std::ostream& operator<<(std::ostream& s, const std::vector<T>& v)
// {
//     s.put('{');
//     for (char comma[]{'\0', ' ', '\0'}; const auto& e : v)
//         s << comma << e, comma[0] = ',';
//     return s << "}\n";
// }


int main()
{
    std::vector<int> vec{0,1,2,3,4,5,6,7};
    // std::cout << vec << std::endl;
    new_section("capacity");
    vec.push_back(8);
    // max_size is the amout of vector elemnts can be out on ram
    std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size()
                << ", Max_size: " << vec.max_size() << std::endl;
    // reserve and shrink to fit
    std::cout << vec.data() << std::endl;
    // relocate to new location if the reserve > capacity usfull in case of multiple insertions
    vec.reserve(32); 
    std::cout << vec.data() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    // shrink to capacity() to size()
    vec.shrink_to_fit();
    std::cout << "After shrink_to_fit: " << vec.capacity() << ", Size: " << vec.size() << std::endl;
    new_section("moifiers");
    // emplace_back doesn't call move or copy constructor hence better performance
    vec.push_back(9);
    vec.emplace_back(10);
    std::cout << vec[9] << ", " << vec[10] << std::endl;
    int x = 11;
    vec.push_back(x);
    x++;
    vec.emplace_back(x);
    std::cout << vec[11] << ", " << vec[12] << std::endl;
    vec.emplace(vec.begin(), -1);
    std::cout << vec[0] << std::endl;
    
}