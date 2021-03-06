#ifndef GAME_H

#define GAME_H

/***********************************
 * Manages the generation of a move,
 * the initialization of the game
 * board with ships and parses all
 * messages sent from the server.
 ***********************************/

#include "Network.h"
#include "GameBoard.h"
#include "MoveGenerator.h"
#include "RandomGenerator.h"
#include "SequentialGenerator.h"
#include "Ship.h"
#include "Move.h"
#include <stdio.h>
#include <string.h>

#define NUM_RESPONSE_TOKENS 3

enum moveTypes_t {RAND, SEQ};

class Game
{
public:
    Game( int x, int y, int z, moveTypes_t moveType, Network* network, char* user, char* pass );
    
    bool run();
    
    ~Game();
    
private:
    /***************************************
     * FUNCTIONS
     ***************************************/
    
    bool login();
    
    void placeShips();
    
    char* makeMove();
    
    bool gameIsOver();
    
    bool matchIsOver();
    
    char* formatMoveMessage(Move* move);
    
    char* formatLoginMessage();
    
    void tokenizeResponse(char* response);
    
    
    
    /***************************************
     * VARIABLES
     ***************************************/
    
    moveTypes_t moveType;
    
    MoveGenerator* generator;
    
    Network* network;
    
    GameBoard* board;
    
    char* user;
    char* pass;
    
    char* responseTokens[NUM_RESPONSE_TOKENS];
    
    ShipLinkList targetList;
    
    //int gameNum;
};

#endif
