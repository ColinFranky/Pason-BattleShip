#ifndef RANDOMGENERATOR_H

#define RANDOMGENERATOR_H

#include "MoveGenerator.h"
#include <cstdlib>
#include <ctime>

//class MoveGenerator;
//class GameBoard;

class RandomGenerator:virtual public MoveGenerator
{
public:
	RandomGenerator(GameBoard* board);
	
	Move* generateMove();
	
	int generator();

private:
	Move currentMove;

};

#endif