#ifndef _GRID_H_
#define _GRID_H_

#include "Cell.h"

#define GRID_SIZE 2
#define GRID_WIDTH 250
#define GRID_HEIGHT 250
#define WIDTH GRID_WIDTH*GRID_SIZE
#define HEIGHT GRID_HEIGHT*GRID_SIZE

class Grid
{
    private:
        Cell cells[GRID_WIDTH * GRID_HEIGHT];
    public:
        Grid();
        int index(int x, int y);
        Cell* getCell(int x, int y);
};

#endif