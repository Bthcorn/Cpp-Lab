#include <iostream>

#define LOG(x) std::cout << x << std::endl;

struct Player
{
public:
    int x, y;
    int speed;

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

struct Vec2
{
    float x, y;

    Vec2 Add(const Vec2 &other) const
    {
        return Vec2{x + other.x, y + other.y};
    }
};

int main()
{
    Player player;
    player.Move(1, -1);
}