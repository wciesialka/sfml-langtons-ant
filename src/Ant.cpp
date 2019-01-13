#include "Ant.h"

Ant::Ant(int x, int y)
{
    this->x = x;
    this->y = y;
    this->dir = UP;
}

void Ant::turnLeft()
{
    switch(this->dir)
    {
        case UP:
            this->dir = LEFT;
            break;
        case LEFT:
            this->dir = DOWN;
            break;
        case DOWN:
            this->dir = RIGHT;
            break;
        case RIGHT: 
            this->dir = UP;
            break;
        default:
            break;
    }
}

void Ant::turnRight()
{
    switch(this->dir)
    {
        case UP:
            this->dir = RIGHT;
            break;
        case RIGHT: 
            this->dir = DOWN;
            break;
        case DOWN: 
            this->dir = LEFT;
            break;
        case LEFT: 
            this->dir = UP;
            break;
        default: 
            break;
    }
}

void Ant::moveForward()
{
    switch(this->dir)
    {
        case UP: 
            this->y--;
            break;
        case RIGHT: 
            this->x++;
            break;
        case DOWN: 
            this->y++;
            break;
        case LEFT: 
            this->x--;
            break;
        default:
            break;
    }
}