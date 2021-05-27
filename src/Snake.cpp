#include "Snake.h"

void Snake::updateSnake(dir newDir, bool gotFood)
{
    _tail = _Snake_Body.back();

    _snakeMovement +=speed;
    if(_snakeMovement > 1.0)
    {
        if(newDir != dir::NO_DIR)
        {
            moveSnake(newDir);
        }
        else
        {
            moveSnake(_Snake_Body.front().getDirection());
        }
    }
    if(gotFood)
    {
        growSnake();
        speed +=speed;
    }
}

void Snake::moveSnake(dir dirctn)
{   
    int i = _Snake_Body.size() - 1;
    for(; i > 0; i--)
    {
        _Snake_Body.at(i).updateDirection(_Snake_Body.at(i-1).getDirection());
        _Snake_Body.at(i).moveBox();
    }
    _Snake_Body.at(i).updateDirection(dirctn);
    _Snake_Body.at(i).moveBox();

    
    for(int i = _Snake_Body.size() - 1; i > 0; i--)
    {
        if(_Snake_Body.at(i).getLocation().X == _Snake_Body.at(0).getLocation().X &&
        _Snake_Body.at(i).getLocation().Y == _Snake_Body.at(0).getLocation().Y)
        {
            alive = false;
        }
    }
        
}

void Snake::growSnake()
{
    _Snake_Body.emplace_back(Box(_tail));
}

int Snake::getSnakeLen()
{
    return _Snake_Body.size();
}

Point Snake::getSnakeBoxLocationAt(int location)
{
    return _Snake_Body.at(location).getLocation(); 
}

dir Snake::getSnakeDirection()
{
    return _Snake_Body.front().getDirection();
}
