#include "Ship.h"

Ship::Ship( Move* center, int radX, int radY, int radZ, ships_t shipType )
{
    this->center = center;
    
    radiusX = radX;
    radiusY = radY;
    radiusZ = radZ;
    
    this->shipType = shipType;
    
    points = ShipLinkList();
}



bool Ship::placeShip( Ship** ships )
{
    gameNum = 100;
    center  = new Move(-1, -1, -1);
    
    bool centerValid = false;
    
    int count = 0;
     
    printf( "\nGenerating coordinates.\n" );
    while( !centerValid && count < 1000 )
    {
        // Generate x
        //center->x = (rand() % (9 - 2*radiusX)) + radiusX;
        
        // Generate y
        //center->y = (rand() % (9 - 2*radiusY)) + radiusY;
        
        // Generate z
        //center->z = (rand() % (9 - 2*radiusZ)) + radiusZ;
        switch (shipType) {
            case FRI:
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
        
        centerValid = true;
        
        //printf( "\nChecking coordinates.\n" );
        for( int i = 0; i < NUM_SHIPS; i++ )
        {
            if( ships[i]->points.head == NULL || i == shipType )
                continue;
            
            //printf( "\nChecking coordinates.\n" );
            
            ShipNode* cur = points.head;
            
            srand( time(NULL) );
            
            while( cur != NULL )
            {
                ShipNode* otherCur = ships[i]->points.head;
                
                while( otherCur != NULL )
                {
                    if( otherCur->position->x == cur->position->x &&
                       otherCur->position->y == cur->position->y &&
                       otherCur->position->z == cur->position->z )
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
        
        /*if( false )
        {
            center->x = ((center->x + 1) % (9 - 2*radiusX)) + radiusX;
            if(center->x == radiusX)
            {
                center->y = ((center->y + 1) % (9 - 2*radiusY)) + radiusY;
                if(center->y == radiusY){
                    center->z = ((center->z + 1) % (9 - 2*radiusZ)) + radiusZ;
                }
            }
        }*/
        
        count++;
    }
    
    if( count >= 1000 )
        return false;
    
    return true;
}



void Ship::addPointsFrigate()
{
    /*center->x = 1;
    center->y = 9;
    center->z = 8;
    
    Move* point = new Move( (center->x - 1), center->y, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z );
    points.add( center );
    
    point = new Move( (center->x + 1), center->y, center->z );
    points.add( point );*/
    
    
//============================================
    
    
    center->x = 0;
    center->y = 9;
    center->z = 8;
    
    Move* point = new Move( center->x, center->y, (center->z - 1) );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z );
    points.add( center );
    
    point = new Move( center->x, center->y, (center->z + 1) );
    points.add( point );
}



void Ship::addPointsDestroyer()
{
    /*center->x = 4;
    center->y = 4;
    center->z = 6;
    
    Move* point = new Move( center->x - 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z );
    points.add( center );
    
    point = new Move( center->x + 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y + 1, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y - 1, center->z );
    points.add( point );*/
    
    
//===============================================================    
    
    
    center->x = 2;
    center->y = 3;
    center->z = 7;
    
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
    /*center->x = 7;
    center->y = 4;
    center->z = 9;
    
    Move* point = new Move( center->x, center->y - 2, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y - 1, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z );
    points.add( center );
    
    point = new Move( center->x, center->y + 1, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y + 2, center->z );
    points.add( point );*/
    

// ================================================================
    
    
    center->x = 7;
    center->y = 4;
    center->z = 8;
    
    Move* point = new Move( center->x, center->y - 2, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y - 1, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z );
    points.add( center );
    
    point = new Move( center->x, center->y + 1, center->z );
    points.add( point );
    
    point = new Move( center->x, center->y + 2, center->z );
    points.add( point );
}

void Ship::addPointsCarrier()
{
    center->x = 7;
    center->y = 2;
    center->z = 2;
    
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
    /*center->x = 1;
    center->y = 7;
    center->z = 3;
    
    Move* point = new Move( center->x - 1, center->y + 1, center->z );
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
    points.add( point );*/
    
    
// ========================================================================
    
    center->x = 2;
    center->y = 8;
    center->z = 2;
    
    Move* point = new Move( center->x - 1, center->y, center->z + 1 );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z + 1 );
    points.add( point );
    
    point = new Move( center->x + 1, center->y, center->z + 1 );
    points.add( point );
    
    point = new Move( center->x - 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x + 1, center->y, center->z );
    points.add( point );
    
    point = new Move( center->x - 1, center->y, center->z - 1 );
    points.add( point );
    
    point = new Move( center->x, center->y, center->z - 1 );
    points.add( point );
    
    point = new Move( center->x + 1, center->y, center->z - 1 );
    points.add( point );
    
}



char* Ship::toString()
{
    printf( "\nGenerating string.\n" );
    
    char* code = new char[32];
    
    switch (shipType) {
        case FRI:
            strcpy( code, "FF" );
            break;
            
        case BAT:
            strcpy( code, "BB" );
            break;
            
        case CAR:
            strcpy( code, "CVL" );
            break;
            
        case SUB:
            strcpy( code, "SSK" );
            break;
            
        case DES:
            strcpy( code,  "DDH" );
            break;
            
        default:
            break;
    }
    
    char* message = new char[512];
    
    sprintf( message, "%s:", code );
    
    ShipNode* cur = points.head;
    
    char* temp = new char[64];
    
    while( cur != NULL )
    {
        printf( "\n\nX: %d, Y: %d, Z: %d\n\n", cur->position->x, cur->position->y, cur->position->z );
        
        if( cur->next != NULL )
        {
            sprintf(temp, "%d,%d,%d;", cur->position->x, cur->position->y, cur->position->z);
            
            printf( "\n\n%s\n\n", temp );
            
            strcat( message, temp );
        }
        else
        {
            sprintf(temp, "%d,%d,%d", cur->position->x, cur->position->y, cur->position->z);
            
            strcat( message, temp );
        }
        
        printf( "\nMESSAGE: %s\n", message );
        
        cur = cur->next;
    }
    
    return message;
}