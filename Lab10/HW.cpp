#include <iostream>
#include <random>
#include <ctime>
#include <memory>
#include <vector>
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
    // std::array<std::array<char, 15>, 15> maze;
    std::vector<std::vector<char>> maze;
    char wall = '#';
    char path = ' ';
    char start = 'S';
    char end = 'E';
    size_t path_in = 0;
    size_t path_out = 0;

public:
    Maze()
    {
        Rand_Int rand(1, 13);
        path_in = rand();
        path_out = rand();
        maze.resize(size, std::vector<char>(size, wall));
        maze[0][path_in] = start;
        maze[size - 1][path_out] = end;
    }

    // void generate()
    // {
    //     Rand_Int rand(0, 1);
    //     // reserve vector size
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
        // size_t path_pos = rand_path_pos();
        size_t temp_start = 0;
        size_t temp_end = 0;
        for (size_t i = 1; i < size - 1; i++)
        {
            size_t path_pos = rand_path_pos();
            temp_start = path_pos;
            for (size_t j = 1; j < size - 1; j++)
            {
                if (j == path_pos)
                { 
                    Rand_Int rand_path_length(0, 13 - path_pos);
                    // maze[i][j] = path;
                    size_t path_length = rand_path_length();
                    for (size_t k = 0; k < path_length; k++)
                    {
                        
                        if (j + k < size - 1)
                        {
                            maze[i][j + k] = path;
                            //find the end of the path
                            temp_end = j + k - 1;
                        }
                    }
                }
            }
            Rand_Int new_path_pos(temp_start, temp_end);
            path_pos = new_path_pos();
            maze[i][path_pos] = path;
        }
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
