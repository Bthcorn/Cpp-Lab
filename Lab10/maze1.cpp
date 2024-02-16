#include <iostream>
#include <random>
#include <vector>

void generateMaze(std::vector<std::vector<char>>& maze, int rows, int cols) {
    // Initialize maze with walls
    maze.assign(rows, std::vector<char>(cols, '#'));

    // Generate random entry and exit points
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, rows - 2);
    int entryRow = dis(gen);
    int exitRow = dis(gen);
    maze[0][entryRow] = '.';
    maze[rows - 1][exitRow] = '.';

    // Generate walls randomly
    for (int row = 1; row < rows - 1; ++row) {
        for (int col = 1; col < cols - 1; ++col) {
            int random = dis(gen);
            if (random % 3 == 0) { // Adjust this probability for more or fewer walls
                maze[row][col] = ' ';
            }
        }
    }
}

void displayMaze(const std::vector<std::vector<char>>& maze) {
    for (const auto& row : maze) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<char>> maze;
    generateMaze(maze, 15, 15);
    displayMaze(maze);
    return 0;
}  