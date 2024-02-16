#include <iostream>
#include <random>
#include <vector>
#include <stack>

void generateRow(std::vector<char>& row, bool randomWalls) {
    std::random_device rd;
    std::default_random_engine re(rd());
    std::uniform_int_distribution<int> rand_wall(0, row.size() - 1);
    int count = 0;
    if (randomWalls) {

        // Place random walls in the row
        row[0] = '#';
        for (size_t i = 1; i < row.size(); ++i) {
            if (rand_wall(re) % 2 == 0 && count != 3) {  // Randomly decide whether to place a wall or not
                row[i] = ' ';
                count++;
            } else {
                row[i] = '#';
            }
        }
        row[row.size() - 1] = '#';
    } else {
        // Generate a row with all walls
        row[0] = '#';
        bool randomWalls = (rand_wall(re) % 2 == 0);
        for (size_t i = 1; i < row.size(); ++i) {
            row[i] = ' ';
        }
        if (randomWalls) 
        {
            row[rand_wall(re)] = '#';
        }
        row[row.size() - 1] = '#';
    }
}

void printMaze(const std::vector<std::vector<char>>& maze, int path_in, int path_out) {
    for (const auto& row : maze) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
    if (maze[maze.size() - 1][path_out] == '.') {
        std::cout << "Path found!" << std::endl;
    } else {
        std::cout << "No path found!" << std::endl;
    }
}

void printMaze(const std::vector<std::vector<char>>& maze) {
    for (const auto& row : maze) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}


void makeSolutionPath(std::vector<std::vector<char>>& maze, int path_in, int path_out) {
    // find one path from the top to the bottom and mark .
    std::stack<std::pair<int, int>> s;
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));

    s.push({0, path_in});
    while (!s.empty()) {
        auto [row, col] = s.top();
        s.pop();
        if (row < 0 || row >= maze.size() || col < 0 || col >= maze[0].size() || maze[row][col] != ' ' || visited[row][col]) {
            continue;
        }
        visited[row][col] = true;
        maze[row][col] = '.';
        s.push({row, col + 1});
        s.push({row, col - 1});
        s.push({row + 1, col});
        s.push({row - 1, col});
    }

}

int main() {
    const size_t size = 15;
    std::vector<std::vector<char>> maze(size, std::vector<char>(size, '#'));

    std::random_device rd;
    std::default_random_engine re(rd());
    std::uniform_int_distribution<int> rand_wall(0, maze[1].size() - 1);
    std::uniform_int_distribution<int> rand_path(1, maze[1].size() - 2);
    int path_in = rand_path(re);
    int path_out = rand_path(re);
    maze[0][path_in] = ' ';
    maze[size - 1][path_out] = ' ';
    for (size_t i = 1; i < size - 1; ++i) {
        bool randomWalls = (i % 2 == 0); // Decide whether to generate random walls or not
        generateRow(maze[i], randomWalls);
        if (i == 1) {
            maze[i][path_in] = ' ';
        }
        if (i == size - 2) {
            maze[i][path_out] = ' ';
        }
    }
    printMaze(maze);
    std::cout << std::endl;

    makeSolutionPath(maze, path_in, path_out);
    // Print the maze
    printMaze(maze, path_in, path_out);

    return 0;
}