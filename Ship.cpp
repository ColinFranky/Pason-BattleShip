#include <Ship.h>

Ship::Ship( Move* center, int radX, int radY, int radZ, ships_t shipType )
{
    this->center = center;
    
    radiusX = radX;
    radiusY = radY;
    radiusZ = radZ;
    
    this->shipType = shipType
    
    points = ShipLinkedList();
}



void Ship::placeShip( Ship[] ships )
{
    center  = new Move(-1, -1, -1);
    
    bool centerValid = false;
    
    while( !centerValid )
    {
        // Generate x
        center->x = (rand() % (9 - 2*radiusX)) + radiusX;
        
        // Generate y
        center->y = (rand() % (9 - 2*radiusY)) + radiusY;
        
        // Generate z
        center->z = (rand() % (9 - 2*radiusZ)) + radiusZ;
        
        switch (shipType) {
            case FRIG:
                addPointsFrigate();
                break;
            case BAT:
                addPointsBattle();
                break;
            case CAR:
                addPointsCarrier();
                break;
            case SUB:
                addPointsSub();
                break;
            case DES:
                addPointsDestroyer();
                break;
                
            default:
                break;
        }
        
        Node* cur = points.head;
        
        while( cur != NULL )
        {
            Node* otherCur = other->points.head;
            
            while( otherCur != NULL )
            {
                if( otherCur.point == cur.point )
                {
                    centerValid = false;
                    break;
                }
                
                otherCur = otherCur->next;
            }
                
            if( centerValid == false )
                break;
            
            cur = cur->next;
        }
    }
}



void Ship::addPointsFrigate()
{
    Move* point = new Move( (center->x - 1), center->y, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z );
    points.add( center );
    
    point = new Move( (center->x + 1), center->y, center->z );
    points.add( point );
}



void Ship::addPointsDestroyer()
{
    Move* point = new Move( center->x - 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z );
    points.add( center );
    
    point = new Move( center->x + 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y + 1, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y - 1, center->z );
    points.add( point );
}

void Ship::addPointsSub()
{
    Move* point = new Move( center->x - 2, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x - 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z );
    points.add( center );
    
    point = new Move( center->x + 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x + 2, center->y, center->z );
    points.add( point );
}

void Ship::addPointsCarrier()
{
    Move* point = new Move( center->x - 2, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x - 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z );
    points.add( center );
    
    point = new Move( center->x + 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x + 2, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y - 2, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y - 1, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y + 1, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y + 2, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z - 2 );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z - 1 );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z + 1 );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z + 2 );
    points.add( point );
}

void Ship::addPointsBattle()
{    
    point = new Move( center->x - 1, center->y + 1, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y + 1, center->z );
    points.add( point );
    
    point = new Move( center->x + 1, center->y + 1, center->z );
    points.add( point );
    
    point = new Move( center->x - 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x + 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x - 1, center->y - 1, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y - 1, center->z );
    points.add( point );
    
    point = new Move( center->x + 1, center->y - 1, center->z );
    points.add( point );
}