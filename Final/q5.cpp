#include <iostream>
#include <vector>

class Game {
public:
    virtual bool isValidMove(int x, int y) = 0;
    virtual void printBoard() = 0;
    virtual bool isWinner() = 0;
    virtual void makeMove(int x, int y, char ch) = 0;
};


class TicTacToe : public Game {
private:
    std::vector<std::vector<char>> board;
public:
    TicTacToe() {
        board.resize(3, std::vector<char>(3, ' '));
    }

    bool isValidMove(int x, int y) {
        if (x < 0 || x > 3 || y < 0 || y > 3 || std::cin.fail()) {
            std::cin.clear();   
            std::cin.ignore(32767, '\n');
            return false;
        }
        if (board[x - 1][y - 1] != ' ') {
            return false;
        }
        return true;
    }

    void printBoard() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if ((i == 0 || i == 2 || i == 4) && (j == 1 || j == 3)) {
                    std::cout << "|";
                } else if (i == 1 || i == 3) {
                    std::cout << "-";
                }
                else {
                    std::cout << board[i / 2][j / 2];
                }
            }
            std::cout << std::endl;
        }
    }

    bool isWinner() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                return true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                return true;
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }
        return false;
    }

    void makeMove(int x, int y, char ch) {
        board[x - 1][y - 1] = ch;
    }
};

int main() {
    TicTacToe t;
    int x, y;
    char ch = 'X';
    bool winner = false;

    while (!winner) {
        t.printBoard();
        std::cout << "Player " << ch <<"," <<"enter the position to make a move: ";
        std::cin >> x >> y;
        while(t.isValidMove(x, y) == false){
            std::cout << "Invalid move!" << std::endl;
            std::cout << "Player " << ch <<"," <<"enter the position to make a move: ";
            std::cin >> x >> y;
        }
        t.makeMove(x, y, ch);
        if (t.isWinner()) {
            winner = true;
            std::cout << "Player " << ch << " wins!" << std::endl;
        }
        if (ch == 'X') {
            ch = 'O';
        } else {
            ch = 'X';
        }
    }
    t.printBoard();

    return 0;
}