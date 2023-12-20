#include <iostream>
#include <vector>

// std::vector<int> lshitf(std::vector<int>& v, int n) {
//     std::vector<int> v2;
//     for (int i = n; i < v.size(); i++) {
//         v2.push_back(v[i]);
//     }
//     // for (int i = 0; i < n; i++) {
//     //     v2.push_back(v[i]);
//     // }
//     return v2;
// }

void lshift1(std::vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        v.erase(v.begin());
    }
}

// std::vector<int> rshitf( std::vector<int>& v, int n) {
//     std::vector<int> v2;
//     for (int i = 0; i < n; i++) {
//         v2.push_back(0);
//     }

//     for (int i = n - 1; i < v.size(); i++) {
//         v2.push_back(v[i]);
//     }
//     return v2;
// }

void rshift1(std::vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        v.insert(v.begin(), 0);
    }
}

int main() {
    std::cout << "Original sequence: ";
    std::vector<int> v = {1, 2, 3, 4, 5};

    // show original sequence
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    std::cout << "\n";

    std::cout << "Left shift by 2: ";
    // std::vector<int> v2 = lshitf(v, 2);
    lshift1(v, 2);
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Right shift by 3: ";
    // std::vector<int> v3 = rshitf(v, 3);
    rshift1(v, 3);
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    return 0;
}