#include <iostream>
#include <vector>

void remove_negative( std::vector<double>& v) {
    // std::vector<double> v2;
    // for (int i = 0; i < v.size(); i++) {
    //     if (v[i] >= 0) {
    //         v2.push_back(v[i]);
    //     }
    // }
    // return v2;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 0) {
            v.erase(v.begin() + i);
        }
    }
}

int main() {
    std::vector<double> v = {0.8, -5.1, 1.6, -6.5, 10.5};
    int arr[10];
    // size_t = sizeof(arr) / sizeof(arr[0]);

    // show original sequence
    std::cout << "Original sequence: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    std::cout << "\n";

    remove_negative(v);
    // show new sequence
    std::cout << "Vector after removing negative numbers: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    
    return 0;
}