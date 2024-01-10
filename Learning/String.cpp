#include <iostream>
#include <string>

void PrintString(const std::string& string)
{
    std::cout << string << std::endl;
}

int main()
{
    const char* name = "Cherno";
    char name2[6] = {'C', 'h', 'e', 'r', 'n', 'o'};
    std::cout << name2 << std::endl;
    // name[2] = 'a'; it is deprecated
    std::cout << name << std::endl;

    std::string name3 = "Cherno";
    // name3[2] = 'a'; this can be done with std::string
    std::cout << name3 << std::endl;
    bool contains = name3.find("no") != std::string::npos;
    std::cout << std::string::npos << std::endl; // if find() does not find the string it returns npos
    std::cout << contains << std::endl;

    return 0;
}