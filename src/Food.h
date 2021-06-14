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
        foodCount = K_MAX_NUMFOODS;
        Eaten = false;
    };
    Food(int xLoc, int yLoc, dir direc = dir::NO_DIR, int r = 255, int g = 0, int b = 0, bool ishead = false, bool eaten = false) : Box{xLoc, yLoc, direc, r, g, b, ishead}, Eaten{eaten}
    {
        foodCount = K_MAX_NUMFOODS;
    }

    bool Eaten;
    int foodCount;
};

#endif /*FOOD_H*/