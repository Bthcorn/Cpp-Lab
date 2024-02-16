#include <iostream>
#include <random>
#include <ctime>
#include <vector>

class Rand_Int
{
public:
    Rand_Int(int low, int high) : dist(low, high) // Correcting constructor initialization
    {
        std::random_device rd;
        re.seed(rd()); // Seed initialization
    }
    int operator()() // Correcting return type to int
    {
        return dist(re); // Using the correct distribution
    }

    ~Rand_Int() = default; // Destructor
private:
    std::default_random_engine re;
    std::uniform_int_distribution<int> dist; // Fixing the distribution type
};

class Maze
{
private:
    size_t size = 15;
    std::vector<std::vector<char>> maze;
    char wall = '#';
    char path = ' ';
    char start = 'S';
    char end = 'E';
    size_t path_in = 0;
    size_t path_out = 0;

public:
    // std::random_device rd;
    // std::default_random_engine re(rd());
    // std::uniform_int_distribution<int> rand_wall(0, row.size() - 1);
    Maze(int rand_path_in, int rand_path_out) : path_in(rand_path_in), path_out(rand_path_out)
    {
        maze.resize(size, std::vector<char>(size, wall));
        maze[0][path_in] = start;
        maze[size - 1][path_out] = end;
    }

    void make_walls()
    {
        int temp_start = path_in;
        int temp_end = path_in;
        Rand_Int rand_path_pos(1, size - 2); // Adjusted to ensure path positions are within bounds
        for (size_t i = 1; i < size - 1; i++)
        {
            size_t path_pos = rand_path_pos();
            for (size_t j = 1; j < size - 1; j++)
            {
                if (j == path_pos)
                {
                    
                    Rand_Int rand_path_length(0, size - 2 - path_pos); // Adjusted to ensure path lengths are within bounds
                    size_t path_length = rand_path_length();
                    for (size_t k = 0; k < path_length; k++)
                    {
                        maze[i][j + k] = path;
                    }
                    temp_end = j + path_length - 1;
                }
            }
            if (i == size - 2)
            {
                temp_end = path_out;
            }

            Rand_Int rand_pos1(temp_start, temp_end); // Adjusted to ensure path lengths are within bounds
            size_t n_path = rand_pos1();
            maze[i][n_path] = path;
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
    // random path_int, path_out
    Rand_Int rand(1, 13);
    int path_in = rand();
    int path_out = rand();

    Maze maze(path_in, path_out);
    maze.make_walls();
    maze.print();

    return 0;
}
