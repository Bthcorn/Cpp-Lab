#include <iostream>
#include <string>

std::string reverseString(std::string str);

int main()
{
    std::cout << "Enter a string: ";
    std::string str;
    std::getline(std::cin, str);
    std::cout << reverseString(str) << std::endl;
    return 0;
}

std::string reverseString(std::string str)
{
    if (str.length() == 1)
    {
        return str;
    }
    else
    {
        return str[str.length() - 1] + reverseString(str.substr(0, str.length() - 1));
    }
}