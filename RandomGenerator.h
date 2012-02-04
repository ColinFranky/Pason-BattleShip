#ifndef RANDOMGENERATOR_H

#define RANDOMGENERATOR_H

#include "MoveGenerator.h"
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <math.h>

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
    int seedTime;

};

#endif