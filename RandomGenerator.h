#ifndef RANDOMGENERATOR_H

#define RANDOMGENERATOR_H

#include "MoveGenerator.h"
#include <cstdlib>
#include <ctime>

class RandomGenerator:virtual public MoveGenerator
{

public:
	RandomGenerator(GameBoard* board);
	
	struct Move generateMove();
	
	int generator();

private:
	struct Move currentMove;

};

#endif