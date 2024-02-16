#include <iostream>
#include <vector>
#include <random>
#include <stack>

using namespace std;

// Define a structure for coordinates
struct Coord {
    int row, col;
};

// Function to generate a random maze
void generateMaze(vector<vector<char>>& maze, int rows, int cols) {
    // Initialize maze with walls
    maze.assign(rows, vector<char>(cols, '#'));

    // Generate random entry and exit points
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, rows - 2);
    int entryRow = dis(gen);
    int exitRow = dis(gen);
    maze[entryRow][0] = '.';
    maze[exitRow][cols - 1] = '.';

    // Generate walls randomly
    for (int row = 1; row < rows - 1; ++row) {
        for (int col = 1; col < cols - 1; ++col) {
            if (dis(gen) % 3 == 0) { // Adjust this probability for more or fewer walls
                maze[row][col] = '#';
            }
        }
    }
}

// Function to display the maze
void displayMaze(const vector<vector<char>>& maze) {
    for (const auto& row : maze) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

// Depth-first search to solve the maze
bool solveMazeDFS(vector<vector<char>>& maze, int entryRow, int exitRow) {
    vector<Coord> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    stack<Coord> st;
    st.push({entryRow, 0});
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));

    while (!st.empty()) {
        Coord current = st.top();
        st.pop();
        int row = current.row;
        int col = current.col;

        if (row == exitRow && col == maze[0].size() - 1) {
            return true;
        }

        visited[row][col] = true;

        for (const auto& dir : directions) {
            int newRow = row + dir.row;
            int newCol = col + dir.col;
            if (newRow >= 0 && newRow < maze.size() && newCol >= 0 && newCol < maze[0].size() &&
                maze[newRow][newCol] == '.' && !visited[newRow][newCol]) {
                st.push({newRow, newCol});
            }
        }
    }

    return false;
}

// Mark the solution path in the maze
void markSolutionPath(vector<vector<char>>& maze, int entryRow, int exitRow) {
    vector<Coord> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    stack<Coord> st;
    st.push({entryRow, 0});

    while (!st.empty()) {
        Coord current = st.top();
        st.pop();
        int row = current.row;
        int col = current.col;

        maze[row][col] = '.';

        for (const auto& dir : directions) {
            int newRow = row + dir.row;
            int newCol = col + dir.col;
            if (newRow >= 0 && newRow < maze.size() && newCol >= 0 && newCol < maze[0].size() &&
                maze[newRow][newCol] == '.') {
                st.push({newRow, newCol});
            }
        }
    }
}

int main() {
    const int rows = 15, cols = 15;
    vector<vector<char>> maze;
    generateMaze(maze, rows, cols);
    displayMaze(maze);

    int entryRow, exitRow;
    for (int i = 0; i < rows; ++i) {
        if (maze[i][0] == '.') {
            entryRow = i;
        }
        if (maze[i][cols - 1] == '.') {
            exitRow = i;
        }
    }

    if (solveMazeDFS(maze, entryRow, exitRow)) {
        cout << "\nSolution found!\n\n";
        markSolutionPath(maze, entryRow, exitRow);
        displayMaze(maze);
    } else {
        cout << "\nNo solution found.\n";
    }

    return 0;
}
