#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define newLine std::cout << std::endl
int main()
{
    std::vector<int> values =  {9,12,4,6,2,6,32,24,61,65,23};
    std::vector<int> values2 = {9,12,4,6,2,6,32,24};
    std::vector<int> values3;
    std::for_each(values.begin(), values.end(),[](int i){std::cout << i << " " << std::flush;}); newLine;
    std::for_each_n(values.begin(), 4,[](int i){std::cout << i << " " << std::flush;}); newLine;
    if (std::all_of(values.begin(), values.end(),[](int i){return i > 0;}))
    {std::cout << "True, All numbers above zero" << std::endl;}
    if (any_of(values.begin(), values.end(),[](int i){return i % 2 == 0;}))
    {std::cout << "True, There is some Even numbers in there." << std::endl;}
    if (std::none_of(values.begin(), values.end(),[](int i){return i / 100 > 1;}))
    {std::cout << "True, All numbers below 100." << std::endl;}
    std::find(values.begin(), values.end(),23) != values.end() ? 
    std::cout << "Value found" << std::endl : std::cout << "Value Doesn't exist" << std::endl;
    std::find_if(values.begin(), values.end(), [](int i){return i == 100;}) != values.end() ?
    std::cout << "Value found" << std::endl : std::cout << "Value Doesn't exist" << std::endl;
    std::cout << "Count of 23 : " <<std::count(values.begin(),values.end(), 23) << std::endl;
    std::pair its = std::mismatch(values.begin(), values.end(), values2.begin(), values2.end(),[](int i, int j){return i == j;});
    its.first != values.end() && its.second != values2.end() ?
    std::cout << "First unequal pair: " << *its.first << ", " << *its.second << std::endl : std::cout << "No unequal pair found" << std::endl;
    std::cout << std::equal(values2.begin(),values2.end(), values.begin(),values.end()) << std::endl;
    auto it = std::search(values.begin(),values.end(),values2.begin(),values2.end());
    it != values.end() ? std::cout << "Subsequence found at position: " << std::distance(values.begin(), it) << std::endl : std::cout << "Subsequence not found" << std::endl;
    std::sort(values.begin(), values.end());
    std::cout  << "Minimum number is : " <<*(std::min_element(values.begin(),values.end())) << std::endl;
    std::cout  << "Maximum number is : " <<*(std::max_element(values.begin(),values.end())) << std::endl;
    std::copy(values.begin(),values.end(),std::back_inserter(values3));
    std::for_each(values3.begin(), values3.end(), [](int i){std::cout << i << " " << std::flush;}); newLine;
    std::transform(values.begin(),values.end(),values3.begin(),[](int i){return i*3;});
    std::for_each(values3.begin(), values3.end(), [](int i){std::cout << i << " " << std::flush;}); newLine;
    
  return 0;
}