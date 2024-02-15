#include <iostream>
#include <random>
#include <ctime>
#include <memory>
#include <array>

class Rand_Int
{
public:
    Rand_Int(int low, int high) : dist(low, high) // Fixing constructor initialization
    {
        std::random_device rd;
        re.seed(rd()); // Seed initialization
    }
    int operator()() // Correcting return type to int
    {
        return dist(re); // Using the correct distribution
    }

private:
    std::default_random_engine re;
    std::uniform_int_distribution<int> dist; // Fixing the distribution type
};

class Maze
{
private:
    // std::unique_ptr<char[]> maze;
    // std::unique_ptr<char[][]> maze1;
    size_t size = 15;
    std::array<std::array<char, 15>, 15> maze;
    char wall = '#';
    char path = ' ';
    char start = 'S';
    char end = 'E';
    size_t path_in = 0;
    size_t path_out = 0;

public:
    Maze()
    {
        // maze = std::make_unique<char[]>(size * size);
        Rand_Int rand(1, 13);
        path_in = rand();
        path_out = rand();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                maze[i][j] = wall;
            }
        }
        maze[0][path_in] = start;
        maze[size - 1][path_out] = end;
    }

    // void generate()
    // {
    //     Rand_Int rand(0, 1);
    //     for (size_t i = 1; i < size - 1; i++)
    //     {
    //         for (size_t j = 1; j < size - 1; j++)
    //         {
    //             maze[i][j] = rand() ? path : wall;
    //         }
    //     }
    //     maze[1][1] = start;
    //     maze[size - 2][size - 2] = end;
    // }

    void make_walls()
    {
        Rand_Int rand_path_pos(1, 13);
        Rand_Int rand__path_length(0, 13);
        size_t path_pos = rand_path_pos();
        size_t temp = 0;
        for (size_t i = 0; i < size; i++)
        {
            path_pos = rand_path_pos();
            for (size_t j = 0; j < size; j++)
            {
                // set path in maze

                if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                {
                    if (maze[i][j] != start && maze[i][j] != end && maze[i][j] != path)
                    {

                        maze[i][j] = wall;
                    }
                }
                else if (j == path_pos)
                {
                    maze[i][j] = path;
                    size_t path_length = rand__path_length();
                    for (size_t k = 0; k < path_length; k++)
                    {
                        if (j + k < size - 1)
                        {
                            maze[i][j + k] = path;
                        }
                    }
                }
            }
        }

        // void make_path()
        // {
        //     for (size_t i = 1; i < size - 1; i++)
        //     {
        //         for (size_t j = 1; j < size - 1; j++)
        //         {
        //             maze[i][j] = path;
        //         }
        //     }
    }

    void print()
    {
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                std::cout << maze[i][j];
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Maze maze;
    // maze.generate();
    maze.make_walls();
    // maze.make_path();
    maze.print();

    return 0;
}
