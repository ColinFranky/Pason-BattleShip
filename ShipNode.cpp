#include "ShipNode.h"

ShipNode::ShipNode(Move* position)
{
	this-> position = position;
	next = NULL;
}