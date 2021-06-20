#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>
#include "Box.h"
#include "GameConstants.h"

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
        score = 0;
    }
    //Update the snake based on new direction and food eaten/not-eaten
    void updateSnake(dir newDir = dir::NO_DIR, bool gotFood = false,  bool bit = false, int decrement = 0);
    int getSnakeLen() const;
    Point getSnakeBoxLocationAt(int location) const;
    //Break the snake from the location at which other snake bit it
    void breakSnakeAt(int location);
    dir getSnakeDirection() const;
    void decrementScore(int decrement);
    void incrementScore();
    int getScore() const;
    Box getSnakeHead() const;
    float speed{0.1};
    bool alive;
    bool areSnakeHeadsOnCollisonCourse(const Snake& snake) const;
private:
    std::vector<Box> _Snake_Body;
    void moveSnake(dir dirctn);
    void growSnake();
    float _snakeMovement{0};
    int score;
    Box _tail;
};

#endif /*SNAKE_H*/