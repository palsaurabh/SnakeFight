#include "Snake.h"

void Snake::updateSnake(bool gotFood = false)
{
    _tail = _Snake_Body.back();

    if(gotFood)
    {
        growSnake();
    }

    if(_Snake_Body.front().getX() == 1)
    {

    }
}

void Snake::moveSnake(dir dirctn)
{   
    int i = _Snake_Body.size();
    for(; i > 0; i--)
    {
        _Snake_Body.at(i).updateDirection(_Snake_Body.at(i-1).getDirection());
        _Snake_Body.at(i).moveBox();
    }
    _Snake_Body.at(i).updateDirection(dirctn);
    _Snake_Body.at(i).moveBox();
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

