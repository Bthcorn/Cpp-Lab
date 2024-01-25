#include <iostream>
#include <sstream>

int main()
{
    std::cout << "Enter a number: ";
    int n;
    std::cin >> n;
    // std::cout << std::endl;
    int lines = 2 * n - 1;
    for (int i = 0; i < lines; ++i)
    {
        if (i < n) 
        {
            for (int j = 0; j <= i; ++j)
            {
                std::cout << "*";
            }
        } else 
        {
            for (int j = 0; j < lines - i; ++j)
            {
                std::cout << "*";
            }
        }

        std::cout << std::endl;


    }
    return 0;
}