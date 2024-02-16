#include <iostream>
#include <random>
#include <vector>

int main()
{
    const size_t size = 15;
    std::vector<std::vector<char>> maze(size, std::vector<char>(size, '#'));

    // Generate random walls for every row except the first and last
    for (size_t i = 1; i < size - 1; ++i)
    {
        std::random_device rd;
        std::default_random_engine re(rd());
        std::uniform_int_distribution<int> rand_wall(0, maze[i].size() - 1);

        // Place random walls in the row
        for (size_t j = 1; j < 14; ++j)
        {
            if (rand_wall(re) % 2 == 0) // Randomly decide whether to place a wall or not
            {
                maze[i][j] = '#';
            }
            else
            {
                maze[i][j] = ' ';
            }
        }
    }


    // Print the maze
    for (const auto& row : maze)
    {
        for (char cell : row)
        {
            std::cout << cell;
        }
        std::cout << std::endl;
    }

    return 0;
}