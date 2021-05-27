#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <mutex>
#include "Box.h"
#include "gameConstants.h"

class Food : public Box
{
    public:


    private:
    std::mutex mtx;
};

#endif /*FOOD_H*/