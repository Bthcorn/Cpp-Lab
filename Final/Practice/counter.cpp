#include <iostream>

class Counter {
private:
    int value;
public:
    Counter(int n = 0) : value(n) {}

    // prefix
    Counter operator++() {    
        ++value;
        return *this;
    }

    // postfix
    Counter operator++(int) {
        // save the orginal value
        Counter old(*this);
        ++value;
        return old;
    }

    int getValue() {
        return value;
    }
};

int main() {
    Counter n = 10;
    Counter j = ++n;
    std::cout << "j = " << j.getValue() << '\n';
    Counter k = n++;
    std::cout << "n = " << n.getValue() << '\n';
    std::cout << "k = " << k.getValue() << '\n';
    return 0;
}