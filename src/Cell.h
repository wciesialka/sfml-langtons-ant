#ifndef _CELL_H_
#define _CELL_H_

class Cell 
{
    private:
        bool white;
    public:
        Cell();
        Cell(bool white);
        bool isWhite();
        void invert();
};

#endif