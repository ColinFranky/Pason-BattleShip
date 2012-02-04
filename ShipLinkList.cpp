#include "ShipLinkList.h"

ShipPosition::ShipPosition()
{
	head = NULL;
	tail = NULL;
}

ShipPosition::addNode(Move* location)
{
	if(head == NULL)
	{
		head = new ShipNode(location);
		tail = head;
	}else
	{
		ShipNode* temp = new ShipNode(location);
		tail->next = temp;
	}
}

ShipPosition::~ShipPosition()
{
	ShipNode* temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}