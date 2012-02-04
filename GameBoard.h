#ifndef GAMEBOARD_H

#define GAMEBOARD_H

/***********************************
 * Represents the 3D game board,
 * tracking what segments have been
 * hit, missed or not shot at.
 ***********************************/

#include "Game.h"
#include "Move.h"

enum status_t {UNKNOWN, HIT, MISS};

class GameBoard
{
public:
    GameBoard(int x,int y,int z );
    
    status_t getStatus( Move* move );
    
    void setStatus( Move* move, status_t status );
    
    ~GameBoard();
    
private:
    status_t*** board;
    int xLength;
    int yLength;
    int zLength;
};

#endif