#include <iostream>

enum Example : unsigned char
{
    A, B, C
};

int main()
{
    Example value = B;

    if (value == 1) {
        std::cout << "Hello!" << std::endl; 
    }

    std::cout << value << std::endl;
    return 0;
}