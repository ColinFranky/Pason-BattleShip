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
#include <string.h>

#define NUM_RESPONSE_TOKENS 3

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
    Game( int x, int y, int z, moveTypes_t moveType, Network* network );
    
    bool run();
    
    ~Game();
    
private:
    /***************************************
     * FUNCTIONS
     ***************************************/
    
    bool login();
    
    char* makeMove();
    
    bool gameIsOver();
    
    bool matchIsOver();
    
    char* formatMoveMessage(const struct Move* move);
    
    char* formatLoginMessage();
    
    void tokenizeResponse(const char* response);
    
    
    
    /***************************************
     * VARIABLES
     ***************************************/
    
    moveTypes_t moveType;
    
    MoveGenerator generator;
    
    Network* network;
    
    GameBoard* board;
    
    const char* user;
    const char* pass;
    
    char* responseTokens[NUM_RESPONSE_TOKENS];
};

#endif