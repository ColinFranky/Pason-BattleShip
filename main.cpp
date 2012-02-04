/******************************************
 * This is the main file to start a
 * game with the server and let it execute
 ******************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Network.h"

using namespace std;

const int BOARD_X = 10;
const int BOARD_Y = 10;
const int BOARD_Z = 10;

int main(int argc, char* argv[])
{
    bool matchOver = false;
    int gameNum = 0;
    moveTypes_t moveType = RAND;
    
    if( argc != 6 )
    {
        printf( "USAGE: [server] [port] [username] [password] [moveType]" );
        exit(0);
    }
    
    const char* server = argv[1];
    const int port = (int) atol( argv[2] );
    const char* user = argv[3];
    const char* pass = argv[4];
    
    printf( "\nuser: '%s' pass: '%s'\n", user, pass );
    
    if( strcmp(argv[5], "RAND") == 0 )
    {
        moveType = RAND;
        printf( "Random game.\n" );
    }
    else if( strcmp(argv[5], "SEQ" ) == 0 )
    {
        moveType = SEQ;
        printf( "Sequential game.\n" );
    }
    
    while ( !matchOver )
    {
        Network* network = new Network(/* SERVER, PORT, USER, PASS */);
        
        Game* game = new Game(BOARD_X, BOARD_Y, BOARD_Z, moveType);
        
        matchOver = game->run(network);
        
        printf( "\nGame %d complete\n", gameNum );
        gameNum++;
    }
    
    printf( "\nMatch over.\n" );
    
    return 0;
}