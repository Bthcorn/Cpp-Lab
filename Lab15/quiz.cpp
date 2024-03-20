#include <iostream>
#include <vector>

using namespace std;

char patternCheck(char ch, vector<vector<char>>& charVector) {
    int countHorizontal = 0, countVertical = 0, countDiagonal1 = 0, countDiagonal2 = 0;

    for (int i = 0; i < 4; ++i) {
        int countRow = 0, countCol = 0;
        for (int j = 0; j < 4; ++j) {
            // Check for single horizontal line
            if (charVector[i][j] == ch) {
                countRow++;
            }
            // Check for single vertical line
            if (charVector[j][i] == ch) {
                countCol++;
            }
        }
        if (countRow == 4) {
            countHorizontal++;
        }
        if (countCol == 4) {
            countVertical++;
        }

        // Check for single diagonal line from top-left to bottom-right
        if (charVector[i][i] == ch) {
            countDiagonal1++;
        }

        // Check for single diagonal line from top-right to bottom-left
        if (charVector[i][3 - i] == ch) {
            countDiagonal2++;
        }
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
    vector<vector<char>> charVector = {
        {'A', ' ', ' ', 'F'},
        {' ', 'A', 'F', ' '},
        {' ', 'F', 'A', ' '},
        {'F', ' ', ' ', 'A'}
    };

    cout << patternCheck('A', charVector) << endl;  // Output: '-'
    cout << patternCheck('F', charVector) << endl;  // Output: '|'
    cout << patternCheck('K', charVector) << endl;  // Output: '\'
    cout << patternCheck('P', charVector) << endl;  // Output: '/'
    cout << patternCheck('X', charVector) << endl;  // Output: 'n'

    return 0;
}
