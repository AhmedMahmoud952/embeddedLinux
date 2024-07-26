#include <iostream>

void removeMember(int* array, int size, int number){
    int index = -1;
    for(int i = 0; i < size;i++){
        if(array[i] == number){
            index = i;
        }
    }
    if(index == -1){
        std::cout << "Number doesn't exist in given array" << std::endl;
        return;
    }
    for(int i = index; i < size-1; i++){
        array[i] = array[i+1];
    }
    array[size-1] = 0;
}

int main(int argc, const char** argv) {

    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int number = 0;
    int size = sizeof(array)/sizeof(array[0]);
    std::cout << "Enter a number to be searched: " << std::flush;
    std::cin >>number;
    removeMember(array, size, number);
    for(auto i : array)
    {
        std::cout << i << std::endl;
    }

}