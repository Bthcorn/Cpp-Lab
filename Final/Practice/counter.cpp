#include <iostream>

class Counter {
private:
    int value;
public:
    Counter(int n) : value(n) {}

    // prefix
    Counter operator++() {    
        ++value;
        return Counter(value);
    }

    // postfix
    Counter operator++(int) {
        // save the orginal value
        Counter c(value);
        ++value;
        return c;
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