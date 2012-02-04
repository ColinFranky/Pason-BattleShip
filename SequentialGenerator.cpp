#include "SequentialGenerator.h"


SequentialGenerator::SequentialGenerator(GameBoard* board):MoveGenerator(board)
{
	lastMove.x = 0;
	lastMove.y = 0;
	lastMove.z = 0;
}

struct Move* SequentialGenerator::generateMove(){
    printf( "\nX: %d; Y: %d; Z: %d\n", lastMove.x, lastMove.y, lastMove.z );
    
	lastMove.x = (lastMove.x + 1) % 10;
	if(lastMove.x == 0)
	{
		lastMove.y = (lastMove.y + 1) % 10;
		if(lastMove.y == 0){
			lastMove.z = (lastMove.z + 1) % 10;
		}
	}
	
	/*lastMove.x = lastMove.x % 10;
	lastMove.y = lastMove.y % 10;
	lastMove.z = lastMove.z % 10;*/
	
	return &lastMove;
	
}