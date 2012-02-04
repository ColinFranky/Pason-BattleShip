
#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(GameBoard* board): MoveGenerator(board)
{
	currentMove.x = 0;
	currentMove.y = 0;
	currentMove.z = 0;
    
    prevMove.x = 0;
    prevMove.y = 0;
    prevMove.z = 0;
    
    seedTime = 432;
}

struct Move* RandomGenerator::generateMove()
{    
    currentMove.x = abs((generator() * 41)% 10);
    currentMove.y = abs(generator() % 10);
    currentMove.z = abs((generator() * 17)%10);
    
    //printf("\n\nX: %d, Y: %d, Z: %d\n\n", currentMove.x, currentMove.y, currentMove.z);
    
    
    while( gameBoard->getStatus(&currentMove) != UNKNOWN )
    {
        currentMove.x = (currentMove.x + 1) % 10;
        if(currentMove.x == 0)
        {
            currentMove.y = (currentMove.y + 1) % 10;
            if(currentMove.y == 0){
                currentMove.z = (currentMove.z + 1) % 10;
            }
        }
    }
    
    return &currentMove;
	
}

int RandomGenerator::generator(){
	return rand();
}