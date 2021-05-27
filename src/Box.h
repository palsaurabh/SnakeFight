#ifndef BOX_H
#define BOX_H

#include <iostream>
#include "gameConstants.h"

enum class dir {NO_DIR, UP_DIR, DOWN_DIR, LEFT_DIR, RIGHT_DIR};

struct Point
{
    int X;
    int Y;
};

class Box
{
    public:
    Box(){};
    Box(int xLoc, int yLoc, dir direc = dir::NO_DIR, int r = 255, int g = 0, int b = 0, bool ishead = false)
    : _loc{xLoc, yLoc}, _direction{direc}, _R{r}, _G{g}, _B{b}, _isHead{ishead}{}

    void moveBox(dir dirctn);
    void moveBox();
    void updateLocation(Point loc);
    void updateDirection(dir dirctn);
    dir getDirection();
    Point getLocation();
    bool isHead();
    Box& operator=(const Box& box);

    private:
    Point _loc;
    dir _direction{dir::NO_DIR};
    int _R{255};
    int _G{0};
    int _B{0};        
    bool _isHead{false};
};

#endif /*BOX_H*/