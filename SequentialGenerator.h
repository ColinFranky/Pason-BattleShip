#ifndef SEQUENTIALGENERATOR_H

#define SEQUENTIALGENERATOR_H

#include "MoveGenerator.h"
class SequentialGenerator: virtual public MoveGenerator
{

public:
	SequentialGenerator(GameBoard* board);
	Move generateMove();
	
private:
	Move lastMove;

};

#endif