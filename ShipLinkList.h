#ifndef SHIPPOSITIONS_H

#define SHIPPOSITIONS_H

#include "Move.h"

class ShipPositions
{
public:
	ShipNode* head;
	ShipNode* tail;
	void addNode(Move* Location);
	
	~ShipPosition;
private:
};

#endif