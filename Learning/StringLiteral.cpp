#include <iostream>
#include <string>

#include <stdlib.h>

int main()
{
    using namespace std::string_literals;

    std::u32string name0 = U"Cherno"s + U" hello";

    const char* example = R"(Line1
Line2
Line3
Line4

Line5)";

    std::cout << example << std::endl;

    std::string name = "Cherno";
    std::string name2 = std::move(name);

    std::cout << name << std::endl;
    std::cout << name2 << std::endl;

    std::cin.get();
    return 0;
}