#include <Ship.h>

Ship::Ship( Move* center, int radX, int radY, int radZ, ships_t shipType )
{
    this->center = center;
    
    radiusX = radX;
    radiusY = radY;
    radiusZ = radZ;
    
    this->shipType = shipType
}



void Ship::placeShip( Ship[] ships )
{
    center  = new Move(-1, -1, -1);
    
    // Generate x
    center->x = (rand() % (9- 2*radX)) + radX;
    
    // Generate y
    center->y = (rand() % (9- 2*radY)) + radY;
    
    // Generate z
    center->z = (rand() % (9- 2*radZ)) + radZ;
}