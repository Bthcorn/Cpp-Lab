#include <iostream>
#include <string>


std::string reverseString(std::string string)
{
    if (string.length() == 1)
    {
        return string;
    }
    else 
    {
        return string[string.length() - 1] + reverseString(string.substr(0, string.length() - 1));
    }
}

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    std::cout << "\n";
    std::cout << "Reversed string: " << reverseString(input) << "\n";
}