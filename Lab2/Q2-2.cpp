#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter number: ";
    int num;
    std::cin >> num;

    int line = num * 2 - 1;

    for (int i = 0; i <= line; i++) {
        if (i < num) {
            for (int j = 1; j <= i; j++) {
                std::cout << "*";
            }
        } else {
            for (int j = 1; j <= line - i + 1; j++) {
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }
}
    // for (int i = 1; i <= num; ++i) {
    //     for (int j = 1; j <= num - i; ++j) {
    //         std::cout << " ";
    //     }
    //     for (int j = 1; j <= i; ++j) {
    //         std::cout << "*";
    //     }
    //     std::cout << std::endl;
    // }