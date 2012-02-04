#ifndef SHIPNODE_H
#define SHIPNODE_H

#include "Move.h"

class ShipNode
{
public:
	ShipNode(Move* position);
	
	ShipNode* next;
	
	Move* position;
};


#endif