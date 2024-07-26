#include <iostream>

int main(int argc, const char** argv) {
 
    int arr1[4] = {1, 2, 3, 4};
    int arr2[4] = {4, 3, 2, 1};
    int merged[8] ={0};
    
    for(int i = 0; i < 4;i++){
        merged[i] = arr1[i];
        merged[i+4] = arr2[i];
    }


    for(auto item : merged)
    {
        std::cout << item << std::endl;
    }
    
    return 0;
}