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
        speed = K_SNAKE_SPEED;
        _snakeMovement = 0;
        alive = true;
    }

    void updateSnake(dir newDir = dir::NO_DIR, bool gotFood = false);
    int getSnakeLen() ; 
    Point getSnakeBoxLocationAt(int location);
    dir getSnakeDirection();
    float speed{0.1};
    bool alive;

    private:
    
    std::vector<Box> _Snake_Body;
    void moveSnake(dir dirctn);
    void growSnake();
    float _snakeMovement{0};
    Box _tail;
};

#endif /*SNAKE_H*/