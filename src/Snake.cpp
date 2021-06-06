#include "Snake.h"

void Snake::updateSnake(dir newDir, bool gotFood)
{
    _snakeMovement +=speed;
    if(_snakeMovement > 1.0)
    {
        _tail = _Snake_Body.back();
    
        if(newDir != dir::NO_DIR)
        {
            moveSnake(newDir);
        }
        else
        {
            moveSnake(_Snake_Body.front().getDirection());
        }
        _snakeMovement = 0;
    }
    if(gotFood)
    {
        growSnake();
        incrementScore();
        // std::cerr<<"Snake Grown"<<'\n';
        speed += K_SPEED_INCREMENTS;
    }
}

void Snake::moveSnake(dir dirctn)
{
    // std::cerr<<"Snake Size: "<<_Snake_Body.size()<<'\n';
    // std::cerr<<"Existing head box: X: "<<_Snake_Body.at(0).getLocation().X<<" Y: "<<_Snake_Body.at(0).getLocation().Y<<'\n';
    // if(_Snake_Body.size() == 2)
    //     std::cerr<<"Existing head box: X: "<<_Snake_Body.at(1).getLocation().X<<" Y: "<<_Snake_Body.at(1).getLocation().Y<<'\n';

    int i = _Snake_Body.size() - 1;
    for(; i > 0; i--)
    {
        _Snake_Body.at(i).updateDirection(_Snake_Body.at(i-1).getDirection());
        _Snake_Body.at(i).moveBox();
        // std::cerr<<"Updated trailing box: X: "<<_Snake_Body.at(i).getLocation().X<<" Y: "<<_Snake_Body.at(i).getLocation().Y<<'\n';
    }
    _Snake_Body.at(i).updateDirection(dirctn);
    _Snake_Body.at(i).moveBox();
    // std::cerr<<"Updated head box: X: "<<_Snake_Body.at(i).getLocation().X<<" Y: "<<_Snake_Body.at(i).getLocation().Y<<'\n';

    
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

void Snake::incrementScore()
{
    score++;
}
int Snake::getScore()
{
    return score;
}
