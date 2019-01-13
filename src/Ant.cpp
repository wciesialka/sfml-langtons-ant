#include "Ant.h"
#include "Grid.h"
//#include <iostream>

Ant::Ant(int x, int y)
{
    //std::cout << "Making ant!" << std::endl;
    this->x = x;
    this->y = y;
    this->dir = UP;
    //std::cout << "Made ant!" << std::endl;
}

void Ant::turnLeft()
{
    //std::cout << "Turning left!" << std::endl;
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
    //std::cout << "\tTurned left!" << std::endl;
}

void Ant::turnRight()
{
    //std::cout << "Turning right!" << std::endl;
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
    //std::cout << "\tTurned right!" << std::endl;
}

void Ant::moveForward()
{
    //std::cout << "Moving forward!" << std::endl;
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
    if(this->x >= GRID_WIDTH)
    {
        this->x = 0;
    } else if(this->x < 0)
    {
        this->x = GRID_WIDTH-1;
    }
    if(this->y >= GRID_HEIGHT)
    {
        this->y = 0;
    } else if(this->y < 0)
    {
        this->y = GRID_HEIGHT-1;
    }
    //std::cout << "\tMoved forward!" << std::endl;
}

int Ant::getX()
{
    return this->x;
}

int Ant::getY()
{
    return this->y;
}