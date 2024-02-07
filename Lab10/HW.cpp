#include <iostream>
#include <random>
#include <ctime>



int main()
{
    size_t size = 15;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << "#";
        }
        std::cout << std::endl;
    }
    return 0;
}
