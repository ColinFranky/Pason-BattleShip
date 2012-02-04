#include "ShipLinkList.h"

ShipLinkList::ShipLinkList()
{
	head = NULL;
	tail = NULL;
}

void ShipLinkList::add(Move* location)
{
	if(head == NULL)
	{
		head = new ShipNode(location);
		tail = head;
	}else
	{
		ShipNode* temp = new ShipNode(location);
		tail->next = temp;
        tail = temp;
	}
}

ShipLinkList::~ShipLinkList()
{
	ShipNode* temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}