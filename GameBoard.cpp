/***********************************
 * Implementation of GameBoard.h
 ***********************************/

#include "GameBoard.h"

GameBoard::GameBoard( int x, int y, int z )
{
    xLength = x;
    yLength = y;
    zLength = z;
    
    board = new status_t[x];
    
    for( int i = 0; i < x; i++ )
        board[i] = new status_t[y];
    
    for( int i = 0; i < x; i++ )
    {
        for( int j = 0; j < y; j++ )
            board[j] = new status_t[z];
    }
    
    for( int i = 0; i < x; i++ )
        for( int j = 0; j < x; j++ )
            for( int k = 0; k < z; k++ )
                board[i][j][k] = UKNOWN;
}


GameBoard::~Gameboard()
{
    for( int x = 0; x < xLength; x++ )
        for( int y = 0; y < yLength; y++ )
            delete board[x][y][];
    
    for( int x = 0; x < xLength; x++ )
        delete board[x][];
    
    delete board[];
}


status_t GameBoard::getStatus(int x,int y, int z)
{
	return board[x][y][z];
}


void GameBoard::setStatus(int x, int y, int z, status_t status)
{
	if(board[x][y][z] == UNKNOWN )
    {
		board[x][y][z] = status;
	}
}