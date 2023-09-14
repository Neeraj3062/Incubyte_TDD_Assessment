#include <iostream>
using namespace std;

class Spacecraft
{
private:
    int posX, posY, posZ;  // Current position (x, y, z)
    char currentDirection; // Current direction (N, S, E, W, U, D)
    char originalDirection;

public:
    Spacecraft(int initialX, int initialY, int initialZ, char initialDirection, char og)
    {
        posX = initialX;
        posY = initialY;
        posZ = initialZ;
        currentDirection = initialDirection;
        originalDirection = og;
    }

    void printPosition()
    {
        std::cout << "Current Position: (" << posX << ", " << posY << ", " << posZ << "), Direction: " << currentDirection << std::endl;
    }
};

int main()
{
    Spacecraft mySpacecraft(0, 0, 0, 'N', 'N');
    mySpacecraft.printPosition();

    return 0;
}
