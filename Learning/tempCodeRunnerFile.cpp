#include <iostream>

void Helloworld(const char* msg)
{
    std::cout << msg << std::endl;
}

int main()
{
    Helloworld("print");
    return 0;
}