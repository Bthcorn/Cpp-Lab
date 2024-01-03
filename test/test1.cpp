#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    //  or srand(static_cast<unsigned int>(time(0)));
    int x = rand() % 6 + 1;
    std::cout << x << std::endl;
    return 0;
}