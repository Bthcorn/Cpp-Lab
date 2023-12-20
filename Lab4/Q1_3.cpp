#include <iostream>
#include <list>

void remove_negative(std::list<double>& l) {
    l.remove_if([](double x) { return x < 0; });
}

int main() {
    std::list<double> l = {0.8, -5.1, 1.6, -6.5, 10.5};
    // show original sequence
    std::cout << "Original sequence: ";
    for (auto i = l.begin(); i != l.end(); i++) {
        std::cout << *i << " ";
    }

    std::cout << "\n";
    
    remove_negative(l);
    // show new sequence
    std::cout << "List after removing negative numbers: ";
    for (auto i = l.begin(); i != l.end(); i++) {
        std::cout << *i << " ";
    }
    
    return 0;
}