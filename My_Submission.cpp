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
void moveBackward() {

    switch (direction) {
        case 'N':
            y--;
            break;
        case 'S':
            y++;
            break;
        case 'E':
            x--;
            break;
        case 'W':
            x++;
            break;
        case 'U':
            z--;
            break;
        case 'D':
            z++;
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
    void turnUp()
    {
        if (direction != 'U')
        {
            direction = 'U';
        }
    }

    void turnDown()
    {
        if (direction != 'D')
        {
            direction = 'D';
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
int main() {
    // Create a Spacecraft object
    Spacecraft spacecraft(0, 0, 0, 'N', 'N');

    // Move forward
    spacecraft.moveForward();

    // Check if the spacecraft's position changed
    if (spacecraft.getX() == 0 && spacecraft.getY() == 1 && spacecraft.getZ() == 0) {
        std::cout << "Move forward test passed." << std::endl;
    } else {
        std::cerr << "Move forward test failed." << std::endl;
    }

    // Move backward
    spacecraft.moveBackward();

    // Check if the spacecraft's position returned to the initial position
    if (spacecraft.getX() == 0 && spacecraft.getY() == 0 && spacecraft.getZ() == 0) {
        std::cout << "Move backward test passed." << std::endl;
    } else {
        std::cerr << "Move backward test failed." << std::endl;
    }

    return 0;
}
