#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter number: ";
    int num;
    std::cin >> num;

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}