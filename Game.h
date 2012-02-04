#ifndef GAME_H

#define GAME_H

/***********************************
 * Manages the generation of a move,
 * the initialization of the game
 * board with ships and parses all
 * messages sent from the server.
 ***********************************/

#include "Network.h"
#include <stdio.h>

enum ships_t {FRI, SUB, DES, BAT, CAR};

enum moveTypes_t {RAND, SEQ};

struct Move {
    int x;
    int y;
    int z;
};



class Game
{
public:
    Game( int x, int y, int z, moveTypes_t moveType );
    
    bool run(Network* network);
    
private:
    /**
     * Generates a random, valid move.
     *
     * @return - The move that is generated.
     */
    struct Move randomMove();
    
    
    /**
     * Generates a random integer between the bounds
     *
     * @param lowerBound - The lower bound of the possible
     *                     numbers that can be generated
     * @param upperBound - The upper bound of the possible
     *                     numbers that can be generated
     * @param includeBounds - If true, the bounds are possible
     *                        return values.  If false, the bounds
     *                        are not valid return values. 
     *
     * @return - A random integer between the lower and upper bounds.
     */
    int generateInteger( int lowerBound, int upperBound, bool includeBounds );
    
    
    int gameIterations;
    
    
    moveTypes_t moveType;
};

#endif