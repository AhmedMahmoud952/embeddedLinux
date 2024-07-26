#include <iostream>

int main(int argc, const char** argv) {

    int array[10] = {10,40,3,5,9,16,109,20,89,567};
    int size = sizeof(array)/sizeof(array[0]);
    std::cout << "Array berfore sorting" << std::endl;
    for(auto member : array)
    {
        std::cout << member << ", " << std::flush;
    }

    auto sorting = [&array,size](bool reverse = false){
        for (int i = 0; i < size-1; i++)
        {
            for (int j = 0; j < size - i-1; j++)
            {
                if ((array[j] > array[j+1]) && !reverse)
                {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
                else if ((array[j] < array[j+1]) && reverse)
                {
                    int temp = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
        }
    };

    sorting();
    for (int i = 0; i < 2; i++)
    {
        std::cout << std::endl << "Array after sorting" << std::endl;
        for(auto member : array)
        {
            std::cout << member << ", " << std::flush;
        }
        sorting(true);
    }

    return 0;
}