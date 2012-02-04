#ifndef SHIP_H
#define SHIP_H

enum ships_t {FRI, SUB, DES, BAT, CAR};

#define NUM_SHIPS 5

#include "ShipLinkList.h"
#include "ShipNode.h"
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <time.h>

static int gameNum = 0;
static bool setGameNum = false;

class Ship
{
public:
    Ship( Move* center, int radX, int radY, int radZ, ships_t shipType );
    
    Move* center;
    int radiusX;
    int radiusY;
    int radiusZ;
    
    ships_t shipType;
    
    bool placeShip( Ship** ships );
    
    ShipLinkList points;
    
    
    void addPointsFrigate();
    
    void addPointsDestroyer();
    
    void addPointsSub();
    
    void addPointsCarrier();
    
    void addPointsBattle();
    
    char* toString();
};

#endif