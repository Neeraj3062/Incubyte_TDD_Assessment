#include <iostream>
using namespace std;
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

    void moveBackward()
    {
        switch (direction)
        {
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
        // cout<<direction<<" "<<ogdir<<endl;
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
                // cout<<"hi"<<endl;
                direction = 'N';
                ogdir = 'N';
                break;
            }
            else if (ogdir == 'N')
            {
                direction = 'W';
                ogdir = 'W';
                break;
            }
            else if (ogdir == 'S')
            {
                direction = 'E';
                ogdir = 'E';
                break;
            }
            else
            {
                direction = 'S';
                ogdir = 'S';
                break;
            }
        case 'D':
            if (ogdir == 'E')
            {
                direction = 'N';
                ogdir = 'N';
                break;
            }
            else if (ogdir == 'N')
            {
                direction = 'W';
                ogdir = 'W';
                break;
            }
            else if (ogdir == 'S')
            {
                direction = 'E';
                ogdir = 'E';
                break;
            }
            else
            {
                direction = 'S';
                ogdir = 'S';
                break;
            }
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
                break;
            }
            else if (ogdir == 'N')
            {
                direction = 'E';
                ogdir = 'E';
                break;
            }
            else if (ogdir == 'S')
            {
                direction = 'W';
                ogdir = 'W';
                break;
            }
            else
            {
                direction = 'N';
                ogdir = 'N';
                break;
            }
        case 'D':
            if (ogdir == 'E')
            {
                direction = 'S';
                ogdir = 'S';
                break;
            }
            else if (ogdir == 'N')
            {
                direction = 'E';
                ogdir = 'E';
                break;
            }
            else if (ogdir == 'S')
            {
                direction = 'W';
                ogdir = 'W';
                break;
            }
            else
            {
                direction = 'N';
                ogdir = 'N';
                break;
            }
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
    void printPosition()
    {
        std::cout << "Current Position: (" << x << ", " << y << ", " << z << "), Direction: " << direction << std::endl;
    }
};

int main()
{
    Spacecraft spacecraft(0, 0, 0, 'N', 'N');
    string commands; // Example commands
    cin >> commands;
    // spacecraft.printPosition();
    for (int i = 0; i < commands.length(); i++)
    {
        char command = commands[i];
        switch (command)
        {
        case 'f':
            spacecraft.moveForward();
      
            break;
        case 'b':
            spacecraft.moveBackward();
     
            break;
        case 'l':
            spacecraft.turnLeft();

            break;
        case 'r':
            spacecraft.turnRight();
          
            break;
        case 'u':
            spacecraft.turnUp();
          
            break;
        case 'd':
            spacecraft.turnDown();
          
            break;
        }
    }

    spacecraft.printPosition();

    return 0;
}
