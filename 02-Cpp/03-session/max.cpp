#include <iostream>

int maxArray(int* array, int size)
{
    int max = 0;
    for(int i = 0; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }

    }
    return max;
}

int main(int argc, const char** argv) 
{

    int array[5] = {1,32,5,4,91};
    int size = sizeof(array)/sizeof(array[0]);
    std::cout<<maxArray(array,size)<<std::endl;
}