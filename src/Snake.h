#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>
#include "Box.h"
#include "gameConstants.h"


class Snake
{
    public:
    Snake(int x, int y, int color)
    {
        _Snake_Body.emplace_back(Box(x, y, dir::NO_DIR, color, color, 0, true));
        _tail = Box(0, 0, dir::NO_DIR, 255, 0, 0, false);
    }
    void updateSnake(bool gotFood = false);
    int getSnakeLen();
    Point getSnakeBoxLocationAt(int locatoin);

    private:
    std::vector<Box> _Snake_Body;
    void moveSnake(dir dirctn);
    void growSnake();
    Box _tail;
};

#endif /*SNAKE_H*/