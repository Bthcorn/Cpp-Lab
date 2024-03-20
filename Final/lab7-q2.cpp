#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
#include <iomanip>


int findMaxInt(std::array<int, 10>& arr, int max = 0, int i = 0)
{
    if (i == arr.size()) {
        return  max;
    }
    else {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
        return findMaxInt(arr, max, i + 1);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    std::array<int, 10> randomArr;

    for (size_t i = 0; i < randomArr.size(); i++)
    {
        randomArr[i] = rand() % 100 + 1;
    }

    for (size_t i = 0; i < randomArr.size(); i++)
    {
        std::cout << randomArr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "The max number is: " << findMaxInt(randomArr) << "\n";
}