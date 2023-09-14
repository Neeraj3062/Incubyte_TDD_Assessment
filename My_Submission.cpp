#include <iostream>

class Spacecraft
{
private:
    int x, y, z;    // Current position (x, y, z)
    char direction; // Current direction (N, S, E, W, U, D)
    char ogdir;

public:
    Spacecraft(int initialX, int initialY, int initialZ, char initialDirection, char og)
    {
        x = initialX;
        y = initialY;
        z = initialZ;
        direction = initialDirection;
        ogdir = og;
    }

    void moveForward()
    {
        switch (direction)
        {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        case 'U':
            z++;
            break;
        case 'D':
            z--;
            break;
        }
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
    int getZ()
    {
        return z;
    }

    void printPosition()
    {
        std::cout << "Current Position: (" << x << ", " << y << ", " << z << "), Direction: " << direction << std::endl;
    }
};

int main()
{
    Spacecraft mySpacecraft(0, 0, 0, 'N', 'N');

    // Test moving forward
    mySpacecraft.moveForward();

    // Check if the Y-coordinate increases
    if (mySpacecraft.getY() == 1)
    {
        std::cout << "Move forward test passed." << std::endl;
    }
    else
    {
        std::cout << "Move forward test failed." << std::endl;
    }
    mySpacecraft.printPosition();
    return 0;
}
