/***********************************
 * Implementation of Game.h
 ***********************************/

#include "Game.h"

using namespace std;

Game::Game( int x, int y, int z,
           moveTypes_t moveType, Network* network,
           char* user, char* pass )
{
    this->board = new GameBoard( x, y, z );
    this->network = network;
    
    switch( moveType )
    {
        SEQ:
            this->generator = new SequentialGenerator( board );
            break;
        RAND:
        default:
            this->generator = new RandomGenerator( board );
            break;
    }
}


Game::~Game()
{
    // Destructor
}



bool Game::run()
{
    printf( "The game is running...\n" );
    
    bool loggedIn = false;
    
    for(int i = 0; i < 100 && !loggedIn; i++ )
        login();
    
    if( !loggedIn )
    {
        printf( "\n\n********** UNABLE TO LOG IN ************\n\n" );
        exit(0);
    }
    
    bool gameOver = false;
    char* response = NULL;
    
    while( !gameOver )
    {
        response = makeMove();
        
        gameOver = gameIsOver();
    }
    
    printf( "The game is over." );
    
    if( matchIsOver() )
        return true;
    
    return false;
}


bool Game::login()
{
    char* message = formatLoginMessage();
    network->sendMessage( message );
    delete message;
    
    return true;
}



char* Game::makeMove()
{
    Move* move = generator->generateMove();
    
    char* message = formatMoveMessage( move );
    network->sendMessage(message);
    delete message;
    
    char* response;
    
    while( (response = network->receiveMessage()) == NULL );
    
    tokenizeResponse( response );
    
    if( strcmp(responseTokens[0], "HIT") == 0 )
        board->setStatus(move, HIT);
    else if( strcmp(responseTokens[0], "MISS") == 0 )
        board->setStatus(move, MISS);
    
    return response;
}



bool Game::gameIsOver()
{
    if( strcmp(responseTokens[1], "GAME") == 0 ||
       strcmp(responseTokens[1], "MATCH") == 0 )
        return true;
    
    return false;
}




bool Game::matchIsOver()
{
    if( strcmp(responseTokens[1], "MATCH") == 0 )
        return true;
    
    return false;
}



char* Game::formatMoveMessage(Move* move)
{
    char* message = new char[256];
    
    /*char* x = new char[32];
    char* y = new char[32];
    char* z = new char[32];
    
    itoa(move->x, x, 10);
    itoa(move->y, y, 10);
    itoa(move->z, z, 10);
    
    strcpy(message, x);
    strcat(message, ",");
    strcat(message, y);
    strcat(message, ",");
    strcat(message, z);
    strcat(message, "\r\n");*/
    
    sprintf(message, "%d,%d,%d\r\n", move->x, move->y, move->z);
    
    return message;
}



char* Game::formatLoginMessage()
{
    char* message = new char[256];
    
    strcpy(message, user);
    
    strcat(message, "|");
    strcat(message, pass);
    strcat(message, "\r\n");
    
    return message;
}



void Game::tokenizeResponse( char* response )
{    
    responseTokens[0] = strtok(response, "|\r\n");
    
    for(int i = 1; i < NUM_RESPONSE_TOKENS && responseTokens[i-1] != NULL; i++ )
        responseTokens[i] = strtok( NULL, "|\r\n" );
}