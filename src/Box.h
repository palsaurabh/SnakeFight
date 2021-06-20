#ifndef BOX_H
#define BOX_H

#include <iostream>
#include "GameConstants.h"

enum class dir
{
    NO_DIR,
    UP_DIR,
    DOWN_DIR,
    LEFT_DIR,
    RIGHT_DIR
};

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
        : _loc{xLoc, yLoc}, _direction{direc}, _R{r}, _G{g}, _B{b}, _isHead{ishead} {}

    // ~Box();
    // Box &operator=(const Box &box);
    // Box(const Box& box);
    //Move the box in a new direction
    void moveBox(dir newdirctn);
    //Move the box  in existing direction
    void moveBox();
    //Update the box location
    void updateLocation(Point loc);
    //Update the box direction
    void updateDirection(dir dirctn);
    dir getDirection() const;
    Point getLocation() const;
    //Is this box a Snake head
    bool isHead() const;
    bool isOnCollisionCourseWith(Box box) const;
private:
    Point _loc;
    dir _direction{dir::NO_DIR};
    [[maybe_unused]] int _R{255};
    [[maybe_unused]] int _G{0};
    [[maybe_unused]] int _B{0};
    bool _isHead{false};
};

#endif /*BOX_H*/