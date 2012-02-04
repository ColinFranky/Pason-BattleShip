#ifndef RANDOMGENERATOR_H

#define RANDOMGENERATOR_H

#include "MoveGenerator.h"
#include <cstdlib>
#include <ctime>

class RandomGenerator:virtual public MoveGenerator
{

public:
	RandomGenerator(status_t* board);
	
	Move generateMove();
	
	int generator();

private:
	Move currentMove;

};

#endif