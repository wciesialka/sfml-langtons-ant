#ifndef _ANT_H_
#define _ANT_H_

enum Direction {UP, RIGHT, DOWN, LEFT};

class Ant 
{
    private: 
        Direction dir;
        int x;
        int y;
    public:
        Ant(int x, int y);
        void turnLeft();
        void turnRight();
        void moveForward();
        int getX();
        int getY();
};

#endif