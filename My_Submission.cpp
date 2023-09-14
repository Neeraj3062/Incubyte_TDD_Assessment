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
    void turnLeft()
    {
        switch (direction)
        {
        case 'N':
            direction = 'W';
            ogdir = 'W';
            break;
        case 'S':
            direction = 'E';
            ogdir = 'E';
            break;
        case 'E':
            direction = 'N';
            ogdir = 'N';
            break;
        case 'W':
            direction = 'S';
            ogdir = 'S';
            break;
        case 'U':
            if (ogdir == 'E')
            {
                direction = 'N';
                ogdir = 'N';
            }
            else if (ogdir == 'N')
            {
                direction = 'W';
                ogdir = 'W';
            }
            else if (ogdir == 'S')
            {
                direction = 'E';
                ogdir = 'E';
            }
            else
            {
                direction = 'S';
                ogdir = 'S';
            }
            break;
        case 'D':
            if (ogdir == 'E')
            {
                direction = 'N';
                ogdir = 'N';
            }
            else if (ogdir == 'N')
            {
                direction = 'W';
                ogdir = 'W';
            }
            else if (ogdir == 'S')
            {
                direction = 'E';
                ogdir = 'E';
            }
            else
            {
                direction = 'S';
                ogdir = 'S';
            }
            break;
        }
    }

    void turnRight()
    {
        switch (direction)
        {
        case 'N':
            direction = 'E';
            ogdir = 'E';
            break;
        case 'S':
            direction = 'W';
            ogdir = 'W';
            break;
        case 'E':
            direction = 'S';
            ogdir = 'S';
            break;
        case 'W':
            direction = 'N';
            ogdir = 'N';
            break;
        case 'U':
            if (ogdir == 'E')
            {
                direction = 'S';
                ogdir = 'S';
            }
            else if (ogdir == 'N')
            {
                direction = 'E';
                ogdir = 'E';
            }
            else if (ogdir == 'S')
            {
                direction = 'W';
                ogdir = 'W';
            }
            else
            {
                direction = 'N';
                ogdir = 'N';
            }
            break;
        case 'D':
            if (ogdir == 'E')
            {
                direction = 'S';
                ogdir = 'S';
            }
            else if (ogdir == 'N')
            {
                direction = 'E';
                ogdir = 'E';
            }
            else if (ogdir == 'S')
            {
                direction = 'W';
                ogdir = 'W';
            }
            else
            {
                direction = 'N';
                ogdir = 'N';
            }
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
    char getDirection()
    {
        return direction;
    }
    void printPosition()
    {
        std::cout << "Current Position: (" << x << ", " << y << ", " << z << "), Direction: " << direction << std::endl;
    }
};
int main()
{
    // Create a Spacecraft object
    Spacecraft mySpacecraft(0, 0, 0, 'N', 'N');

    mySpacecraft.turnLeft();

    // Check if the direction changes to 'W' (west)
    if (mySpacecraft.getDirection() == 'W')
    {
        std::cout << "Turn left test passed." << std::endl;
    }
    else
    {
        std::cout << "Turn left test failed." << std::endl;
    }


    mySpacecraft.turnRight();

    // Check if the direction changes back to 'N' (north)
    if (mySpacecraft.getDirection() == 'N')
    {
        std::cout << "Turn right test passed." << std::endl;
    }
    else
    {
        std::cout << "Turn right test failed." << std::endl;
    }
    mySpacecraft.printPosition();
    return 0;
}
