#ifndef SHIP_H
#define SHIP_H

enum ships_t {FRI, SUB, DES, BAT, CAR};

#define NUM_SHIPS 5

class Ship
{
public:
    Ship( Move* center, int radX, int radY, int radZ, ships_t shipType );
    
    Move* center;
    int radiusX;
    int radiusY;
    int radiusZ;
    
    ships_t shipType;
    
    void placeShip( Ship[] ships);
    
    ShipLinkedList points;
}

#endif