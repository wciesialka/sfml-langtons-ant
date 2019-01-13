#include "Cell.h"

Cell::Cell(bool white)
{
    this->white = white;
}

bool Cell::isWhite()
{
    return this->white;
}

void Cell::invert()
{
    this->white = !this->white;
}