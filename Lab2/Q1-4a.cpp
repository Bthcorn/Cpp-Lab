#include <iostream>
#include <string>
int main()
{
    std::cout << "Please enter P1 name: ";
    std::string p1_name;
    std::getline(std::cin, p1_name);
    std::cout << "Please enter P2 name: ";
    std::string p2_name;
    // std::cin >> p2_name;
    std::getline(std::cin, p2_name);
    std::cout << "Player 1: " << p1_name << std::endl;
    std::cout << "Player 2: " << p2_name << std::endl;

    const std::string player1 = "Player 1: " + p1_name;
    const std::string player2 = "Player 2: " + p2_name;


    const int pad = 1;
    const std::string::size_type rows = pad * 4 + 5;

    const std::string::size_type cols = player1.size() + pad * 2 + 2;

    std::cout << std::endl;

    for (int r = 0; r != rows; ++r) {
        std::string::size_type c = 0;

        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                std::cout << player1;
                c += player1.size();
            }
            else if (r == pad * 2 + 4 && c == pad + 1) {
                std::cout << player2;
                c += player2.size();
            }
            else {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1 || r == pad * 2 + 2) {
                    std::cout << "*";
                }
                else {
                    std::cout << " ";
                }
                ++c;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}