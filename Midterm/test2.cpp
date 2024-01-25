#include <iostream>
#include <string>

std::string FormatNumber(int number) {
    std::string result = std::to_string(number);
    int count = 0;
    for (int i = result.size() - 1; i >= 0; --i) {
        ++count;
        if (count == 3 && i != 0) {
            result.insert(i, ",");
            count = 0;
        }
    }
    return result;
}

int main() {
    int number = 7.e8;
    std::cout << FormatNumber(number) << std::endl;
    return 0;
}