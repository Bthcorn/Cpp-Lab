#include <iostream>
#include <array>

class Entity 
{
public:
    int example[5];
    // int* example = new int[5]; //same as above this one is a pointer to an array of 5 integers

    Entity()
    {
        for (int i = 0 ; i < 5 ; i++) 
        {
            example[i] = 2;
        } //prints out the value of the array (i
    }
};

int main() 
{
    int example[5];  // kind of like a pointer
    example[0] = 2;
    std::array<int, 5> another1; //same as above
    for (int i = 0 ; i < 5 ; i++) 
    {
        example[i] = 2;
    } //prints out the value of the array (i

    int* ptr = example;
    int* another = new int[5]; //same as above
    for (int i = 0 ; i < 5 ; i++) 
    {
        another[i] = 2;
    } //prints out the value of the array


    delete[] another; //deletes the array

    // for (int i = 0 ; i < 5 ; i++) 
    // {
    //     example[i] = 2;
    // } //prints out the value of the array (i
    example[2] = 5;
    *(ptr + 2) = 6; //same as above
    // std::cout << example[0] << std::endl;   
    // std::cout << example << std::endl;
    return 0;
}