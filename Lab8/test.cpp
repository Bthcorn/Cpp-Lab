#include <iostream>

using namespace std;

size_t getSize(double *);
int main()
{
    double numbers[20];

    std::cout << "array size : " << sizeof(numbers);
                               std::cout
              << "\nnumber returned by getSize is "
              << getSize(numbers)
              << std::endl;
}

size_t getSize(double *ptr)
{
    return sizeof(ptr);
}