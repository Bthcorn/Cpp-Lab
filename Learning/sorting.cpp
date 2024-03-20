#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // use like std::greater<int>()

int main() 
{
    std::vector<int> values = {3, 5, 1, 4, 2};
    // std::sort(values.begin(), values.end(), std::greater<int>());
    std::sort(values.begin(), values.end(), [](int a, int b) {
        // return a > b; // return decending order
        if (a == 1) 
        {
            return false;
        } 
        if (b == 1) 
        {
            return true;
        } 
        return a < b;
    });

    for (auto &value : values) {
        std::cout << value << '\n';
    }

    return 0;
}