#ifndef SHIPPOSITIONS_H

#define SHIPPOSITIONS_H

#include "Move.h"
#include "ShipNode.h"
#include <cstddef>

class ShipLinkList
{
public:
    ShipLinkList();
    
	ShipNode* head;
	ShipNode* tail;
	void add(Move* location);
    void remove(ShipNode* node);
	
	~ShipLinkList();
private:
};

#endif