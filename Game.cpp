/***********************************
 * Implementation of Game.h
 ***********************************/

#include "Game.h"

using namespace std;

Game::Game( int x, int y, int z,
           moveTypes_t moveType, Network* network,
           char* user, char* pass )
{
    srand(time(NULL));
    
    this->board = new GameBoard( x, y, z );
    this->network = network;
    
    this->user = user;
    this->pass = pass;
    
    //printf( "\n\nMoveType = %d\n\n", moveType );
    //exit(0);
    
    switch( moveType )
    {
        case SEQ:
            this->generator = new SequentialGenerator( board );
            printf("\n\n********** USING SEQUENTIAL *************\n\n" );
            break;
        case RAND:
            printf("\n\n********** USING RANDOM *************\n\n" );
        default:
            this->generator = new RandomGenerator( board );
            printf("\n\n********** USING DEFAULT *************\n\n" );
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
    
    printf( "Logging in.\n" );
    for(int i = 0; i < 100 && !loggedIn; i++ )
        loggedIn = login();
    
    if( !loggedIn )
    {
        printf( "\n\n********** UNABLE TO LOG IN ************\n\n" );
        exit(0);
    }
    
    printf( "Logged in.\n" );
    
    placeShips();
    
    printf( "Ships placed.\n" );
    
    bool gameOver = false;
    char* response = NULL;
    
    while( !gameOver )
    {
        printf( "Making move.\n" );
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
    printf( "Formatting.\n" );
    char* message = formatLoginMessage();
    
    printf( "\nSENDING: %s\n", message );
    network->sendMessage( message );
    delete message;
    
    char* response;
    while( (response = network->receiveMessage()) == NULL );
    
    printf( "\nRECEIVED: %s\n", response );
    
    return true;
}



void Game::placeShips()
{
    //char* message = (char*) "FF:9,0,0;9,0,1;9,0,2|SSK:9,0,3;9,0,4;9,0,5;9,0,6;9,0,7|DDH:0,1,0;1,0,0;1,1,0;1,2,0;2,1,0|BB:1,1,1;1,1,2;1,1,3;1,2,1;1,2,3;1,3,1;1,3,2;1,3,3|CVL:0,2,2;1,2,2;2,2,2;3,2,2;4,2,2;2,0,2;2,1,2;2,3,2;2,4,2;2,2,0;2,2,1;2,2,3;2,2,4\r\n";
    
    Ship** ships = new Ship*[5];
    
    ships[FRI] = new Ship( NULL, 1, 0, 0, FRI );
    ships[SUB] = new Ship( NULL, 0, 2, 0, SUB );
    ships[BAT] = new Ship( NULL, 1, 1, 1, BAT );
    ships[DES] = new Ship( NULL, 1, 1, 1, DES );
    ships[CAR] = new Ship( NULL, 2, 2, 2, CAR );
    
    bool success = true;
    
    printf( "\nPlacing carrier.\n" );
    if( ships[CAR]->placeShip(ships) )
    {
        printf( "\nPlacing battleship.\n" );
        if( ships[BAT]->placeShip(ships) )
        {
            printf( "\nPlacing destroyer.\n" );
            if( ships[DES]->placeShip(ships) )
            {
                printf( "\nPlacing sub.\n" );
                if( ships[SUB]->placeShip(ships) )
                {
                    printf( "\nPlacing frigate.\n" );
                    if( ships[FRI]->placeShip(ships) )
                        printf( "\nFINISHED PLACING SHIPS\n" );
                    else
                        success = false;
                }
                else
                    success = false;
            }
            else
                success = false;
        }
        else
            success = false;
    }
    else
        success = false;
    
    char* message;
    
    if( !success )
        message = (char*) "FF:9,0,0;9,0,1;9,0,2|SSK:9,0,3;9,0,4;9,0,5;9,0,6;9,0,7|DDH:0,1,0;1,0,0;1,1,0;1,2,0;2,1,0|BB:1,1,1;1,1,2;1,1,3;1,2,1;1,2,3;1,3,1;1,3,2;1,3,3|CVL:0,2,2;1,2,2;2,2,2;3,2,2;4,2,2;2,0,2;2,1,2;2,3,2;2,4,2;2,2,0;2,2,1;2,2,3;2,2,4\r\n";
    else
    {
        message = new char[512];
        
        sprintf( message, "%s|%s|%s|%s|%s\r\n", ships[FRI]->toString(), ships[SUB]->toString(), ships[BAT]->toString(), ships[DES]->toString(), ships[CAR]->toString() );
        
        printf( "\nMESSAGE GENERATED: %s\n", message );
        //exit(0);
    }
    
    printf( "\nSENDING: %s\n", message );
    network->sendMessage( message );
    //delete message;
    
    char* response;
    while( (response = network->receiveMessage()) == NULL );
    
    printf( "\nRECEIVED: %s\n", response );
}



char* Game::makeMove()
{
    Move* move = generator->generateMove();
    
    char* message = formatMoveMessage( move );
    
    printf( "\nSENDING: %s\n", message );
    network->sendMessage(message);
    delete message;
    
    char* response;
    
    while( (response = network->receiveMessage()) == NULL );
    printf( "\nRECEIVED: %s\n", response );
    
    tokenizeResponse( response );
    
    if( strcmp(responseTokens[0], "HIT") == 0 )
    {
        printf( "\nHIT MARKED\n" );
        board->setStatus(move, HIT);
    }
    else if( strcmp(responseTokens[0], "MISS") == 0 )
    {
        board->setStatus(move, MISS);
        printf( "\nHIT MARKED\n" );
    }
    
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
    
    sprintf(message, "%d,%d,%d\r\n", move->x, move->y, move->z);
    
    return message;
}



char* Game::formatLoginMessage()
{
    printf( "Formatting login.\n" );
    char* message = new char[256];
    
    printf( "User: %s\n", user );
    printf( "Pass: %s\n", pass );
    
    sprintf(message, "%s|%s\r\n", user, pass);
    
    return message;
}



void Game::tokenizeResponse( char* response )
{  
    responseTokens[0] = strtok(response, "|");
    
    for(int i = 1; i < NUM_RESPONSE_TOKENS && responseTokens[i-1] != NULL; i++ )
        responseTokens[i] = strtok( NULL, "|" );
}