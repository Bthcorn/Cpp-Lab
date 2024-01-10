#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <ctime>
#include <array>

// std::array<int, 10> randomIntegers() {
//     std::array<int, 10> array;
//     // std::default_random_engine engine(static_cast<unsigned int>(time(0)));
//     // std::uniform_int_distribution<unsigned int> randomInt(1, 100);

//     srand(static_cast<unsigned int>(time(0)));
//     for (size_t i = 0; i < array.size(); i++)
//     {
//         array[i] = rand() % 100 + 1;
//     }
//     return array;
// }

int findMax(std::array<int, 10>& array, int max = 0, int i = 0) {
    if (i == array.size())
    {
        return max;
    }
    else
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        return findMax(array, max, i + 1);
    }
    
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    
    std::array<int, 10> array;

    for (size_t i = 0; i < array.size(); i++)
    {
        array[i] = rand() % 100 + 1;

    }
    std::cout << "Generated 10 random integers between 1 and 100:" << std::endl;

    for (size_t i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "The largest element in the array is: " << findMax(array) << std::endl;
    return 0;

}