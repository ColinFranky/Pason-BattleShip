
#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(status_t* board): MoveGenerator(board)
{
	currentMove.x = 0;
	currentMove.y = 0;
	currentMove.z = 0;

}

Move RandomGenerator::generateMove()
{
	while(1){	
		currentMove.x = generator();
		currentMove.y = generator();
		currentMove.z = generator();
		if(gameBoard.getStatus(currentMove) == UNKNOWN){
			return currentMove;
		}
	}
	
	
}

int RandomGenerator::generator(){
	srand(time(0));
	return rand() % 10;
}