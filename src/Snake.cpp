#include "Snake.h"

void Snake::updateSnake(dir newDir, bool gotFood, bool bitten, int bitAt)
{
    _snakeMovement += speed;

    if (_snakeMovement > 1.0)
    {
        _tail = _Snake_Body.back();

        if (newDir != dir::NO_DIR)
        {
            moveSnake(newDir);
        }
        else
        {
            moveSnake(_Snake_Body.front().getDirection());
        }
        _snakeMovement = 0;
    }

    if (gotFood)
    {
        growSnake();
        incrementScore();
        speed += K_SPEED_INCREMENTS;
    }

    if(bitten)
    {
        decrementScore(getSnakeLen() - bitAt);
        breakSnakeAt(bitAt);
    }
}

void Snake::moveSnake(dir dirctn)
{
    int i = _Snake_Body.size() - 1;
    for (; i > 0; i--)
    {
        _Snake_Body.at(i).updateDirection(_Snake_Body.at(i - 1).getDirection());
        _Snake_Body.at(i).moveBox();
    }
    _Snake_Body.at(i).updateDirection(dirctn);
    _Snake_Body.at(i).moveBox();

    for (int i = _Snake_Body.size() - 1; i > 0; i--)
    {
        if (_Snake_Body.at(i).getLocation().X == _Snake_Body.at(0).getLocation().X &&
            _Snake_Body.at(i).getLocation().Y == _Snake_Body.at(0).getLocation().Y)
        {
            alive = false;
        }
    }
}

void Snake::growSnake()
{
    _Snake_Body.push_back(Box(_tail));
}

int Snake::getSnakeLen() const
{
    return _Snake_Body.size();
}

Point Snake::getSnakeBoxLocationAt(int location) const
{
    return _Snake_Body.at(location).getLocation();
}

void Snake::breakSnakeAt(int location)
{
    _Snake_Body.erase(_Snake_Body.cbegin() + location, _Snake_Body.cend());
}

dir Snake::getSnakeDirection() const
{
    return _Snake_Body.front().getDirection();
}

void Snake::incrementScore()
{
    score++;
}
int Snake::getScore() const
{
    return score;
}

void Snake::decrementScore(int decrement)
{   std::cout<<"Decrement Value = decrement"<<decrement<<'\n';
    score -= decrement;
}

Box Snake::getSnakeHead() const
{
    return _Snake_Body.at(0);
}

bool Snake::areSnakeHeadsOnCollisonCourse(const Snake& snake) const
{
    if(getSnakeHead().isOnCollisionCourseWith(snake.getSnakeHead()))
    {
        return true;
    }

    return false;
}