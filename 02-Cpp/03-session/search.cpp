#include <iostream>

int arraySearch(int* array, int size, int number){
    for(int i = 0; i < size;i++){
        if(array[i] == number){
            return i;
        }
    }
    return -1; // Number not found in the array. 
}

int main(int argc, const char** argv) {

    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int number = 0;
    int size = sizeof(array)/sizeof(array[0]);
    std::cout << "Enter a number to be searched: " << std::flush;
    std::cin >>number;
    std::cout << arraySearch(array,size,number) << std::endl;

}