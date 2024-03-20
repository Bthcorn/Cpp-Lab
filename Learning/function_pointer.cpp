#include <iostream>
#include <vector>

void HelloWorld(int a) 
{
    std::cout << "Hello World!" << a << '\n';
}

void PrintValue(int value) 
{
    std::cout << "Value: " << value << '\n';
}

// passing a function
void ForEach(const std::vector<int> &values, void(*func)(int))
{
    for (int value : values)
        func(value);
}

int main() 
{
    typedef void(*HelloWorldFunciton)(int);
    HelloWorldFunciton function = HelloWorld;
    // auto function = HelloWorld;
    function(8);
    function(9); // void(*function)()

    std::vector<int> values = { 1, 2, 3, 4, 5 };
    ForEach(values, PrintValue);

    // using lambda
    ForEach(values, [](int value) { std::cout <<  "Value: " << value << '\n';});
    return 0;
}