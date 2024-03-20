#include <iostream>

template<typename T>
void Print(T value)
{
    std::cout << value << '\n';
}

template<typename T, int N>
class Array 
{
private:
    int m_Array[N];
public:
    int getSize() const { return N; };
};

int main() 
{
    Print(5);
    // Print<int>(5);
    Print("Hello");
    Print(5.5f);
    Array<int, 10> arr;
    std::cout << arr.getSize();
    return 0;
}