#include "Snake.h"

void Snake::updateSnake()
{
    _tail = _Snake_Body.back();

    if(_Snake_Body.front().)
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
