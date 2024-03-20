#include <iostream>
#include <vector>

char checkPattern(char ch, std::vector<std::vector<char>> &vec) {
    int countHorizontal = 0, countVertical = 0, countDiagonal1 = 0, countDiagonal2 = 0;

    for (int i = 0; i < 4; ++i) {
        int countRow = 0, countCol = 0;
        // for (int j = 0; j < 4; ++j) {
        //     // Check for single horizontal line
        //     if (vec[i][j] == ch) {
        //         countRow++;
        //     }
        //     // Check for single vertical line
        //     if (vec[j][i] == ch) {
        //         countCol++;
        //     }
        // }
        if (vec[i][0] == ch && vec[i][1] == ch && vec[i][2] == ch && vec[i][3] == ch) {
            countRow = 1;
        }

        if (vec[0][i] == ch && vec[1][i] == ch && vec[2][i] == ch && vec[3][i] == ch) {
            countCol = 1;
        }

        if (countRow == 1) {
            countHorizontal++;
        }
        if (countCol == 1) {
            countVertical++;
        }

        // Check for single diagonal line from top-left to bottom-right
        // if (vec[i][i] == ch) {
        //     countDiagonal1++;
        // }

        // Check for single diagonal line from top-right to bottom-left
        // if (vec[i][3 - i] == ch) {
        //     countDiagonal2++;
        // }
    }
    if (vec[1][1] == ch && vec[2][2] == ch && vec[3][3] == ch && vec[0][0] == ch) {
        countDiagonal1 = 4;
    }

    if (vec[0][3] == ch && vec[1][2] == ch && vec[2][1] == ch && vec[3][0] == ch) {
        countDiagonal2 = 4;
    }

    if (countHorizontal == 1) {
        return '-';
    }
    if (countVertical == 1) {
        return '|';
    }
    if (countDiagonal1 == 4) {
        return '\\';
    }
    if (countDiagonal2 == 4) {
        return '/';
    }

    return 'n';
}

int main() {
    std::vector<std::vector<char>> vec = {
        {'X', 'X', 'X', 'X'},
        {' ', 'A', 'F', ' '},
        {' ', 'F', 'A', ' '},
        {'F', ' ', ' ', 'A'}
    };

    std::cout << checkPattern('A', vec) << std::endl;
    std::cout << checkPattern('F', vec) << std::endl;
    std::cout << checkPattern('X', vec) << '\n';
    return 0;
}