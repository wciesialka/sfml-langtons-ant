#include "Grid.h"
#include "Cell.h"

Cell* Grid::getCell(int x, int y)
{
    return &this->cells[x + (GRID_HEIGHT*y)];
}

int Grid::index(int x, int y)
{
    return x + (GRID_HEIGHT*y);
}

Grid::Grid()
{
    //this->cells[GRID_WIDTH*GRID_HEIGHT] = Cell();
    for(int i = 0; i < GRID_WIDTH*GRID_HEIGHT; i++)
    {
        this->cells[i] = Cell(true);
    }
}