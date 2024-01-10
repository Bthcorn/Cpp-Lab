#include <iostream>
#include <cstdlib>
#include <ctime>

#define LOG(x) std::cout << x << std::endl;

void Increment(int* value) {
    (*value)++;
} // this function increments the value of the variable that the pointer is pointing to
// the pointer is passed by value, so the pointer itself is not changed

// pass by reference
void Increment(int& value) {
    value++;
}


int main() {
    int var = 8;
    int* ptr = &var;
    int a = 5;
    int& ref = a;
    ref = 2;
    // --------------------
    // int a = 5;
    // int b = 8;
    // int* ptr = &a;
    // *ptr = 2;
    // ptr = &b;
    // *ptr = 1;
    // in case of pointers, the value of the pointer can be changed


    Increment(&a); // passing the address of a to the function | pass by pointer
    Increment(a); // reference is passed by value
    LOG(a);
    // how to dereference a void pointer?
    *ptr = 10;
    LOG(*ptr); // error: invalid conversion from ‘void*’ to ‘int’ [-fpermissive]
    return 0;
}