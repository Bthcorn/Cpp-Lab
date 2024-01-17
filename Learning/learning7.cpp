#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using String = std::string;

int main() 
{
    int n[] = { 1, 2, 3, 4, 5 };
    std::sort(std::begin(n), std::end(n));
    // std::cout << std::begin(n) << std::endl;
    // std::cout << std::end(n) << std::endl;
    for (int i : n)
    {
        std::cout << i << " ";
    }
    
    return 0;
}