#include "SequentialGenerator.h"


SequentialGenerator::SequentialGenerator(GameBoard* board):MoveGenerator(board)
{
	lastMove.x = 9;
	lastMove.y = 9;
	lastMove.z = 9;
    turnNum = 0;
}

struct Move* SequentialGenerator::generateMove(){
    printf( "\nX: %d; Y: %d; Z: %d\n", lastMove.x, lastMove.y, lastMove.z );
    
    int delta = 13;
    
    if( turnNum == 0 && gameBoard->getStatus( 9, 0, 3 ) == UNKNOWN )
    {
        lastMove.x = 9;
        lastMove.y = 0;
        lastMove.z = 3;
     
        turnNum++;
        
        return &lastMove;
    }
    
    if( turnNum == 1 && gameBoard->getStatus( 2, 2, 2 ) == UNKNOWN )
    {
        lastMove.x = 2;
        lastMove.y = 2;
        lastMove.z = 2;
     
        turnNum++;
        
        return &lastMove;
    }
    
    if( turnNum == 2 )
    {
        lastMove.x = 0;
        lastMove.y = 9;
        lastMove.z = 0;
        
        turnNum++;
        
        return &lastMove;
    }
    
    if( turnNum < 12 )
    {        
        lastMove.x = (lastMove.x + 1) % 10;
        lastMove.y = (lastMove.y - 1) % 10;
        
        if( lastMove.y < 0 ) lastMove.y = lastMove.y * -1;
        
        lastMove.y = (lastMove.z + 1) % 10;
        
        turnNum++;
        
        return &lastMove;
    }
    
    
    if( turnNum == 2 )
    {
        lastMove.x = 9;
        lastMove.y = 0;
        lastMove.z = 0;
        
        turnNum++;
        
        return &lastMove;
    }
    
    
    if( turnNum < 20 )
    {        
        lastMove.x = (lastMove.x - 1) % 10;
        
        if( lastMove.x < 0 ) lastMove.x = lastMove.x * -1;
        
        lastMove.y = (lastMove.y + 1) % 10;
        lastMove.z = (lastMove.z + 1) % 10;;
        
        turnNum++;
        
        return &lastMove;
    }
    
    
    if( turnNum == 20 )
    {        
        lastMove.x = 0;
        lastMove.y = 9;
        lastMove.z = 4;
        
        turnNum++;
        
        return &lastMove;
    }
    
    
    
	lastMove.x = (lastMove.x + delta) % 10;
	if(lastMove.x > 0)
	{
		lastMove.y = (lastMove.y + delta) % 10;
		if(lastMove.y > 0){
			lastMove.z = (lastMove.z + delta) % 10;
		}
	}
    
    
    while( gameBoard->getStatus( &lastMove ) != UNKNOWN )
    {
        lastMove.x = (lastMove.x + 1) % 10;
        if(lastMove.x == 0)
        {
            lastMove.y = (lastMove.y + 1) % 10;
            if(lastMove.y == 0){
                lastMove.z = (lastMove.z + 1) % 10;
            }
        }
    }
	
	turnNum++;
	
	return &lastMove;
	
}