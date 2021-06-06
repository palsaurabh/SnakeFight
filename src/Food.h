#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <mutex>
#include "Box.h"
#include "GameConstants.h"

class Food : public Box
{
    public:
    Food()
    {
        
    };
    Food(int xLoc, int yLoc, dir direc = dir::NO_DIR, int r = 255, int g = 0, int b = 0, bool ishead = false, bool eaten = false):
    Box{xLoc, yLoc, direc, r, g, b, ishead}, Eaten{eaten} {}

    bool Eaten;
};

#endif /*FOOD_H*/