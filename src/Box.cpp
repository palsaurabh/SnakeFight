#include "Box.h"

void Box::moveBox(dir dirctn)
{
    switch (dirctn)
    {
    case dir::UP_DIR:
        if ((_loc.Y-1)> 0)
            _loc.Y-=1;
        break;
    case dir::DOWN_DIR:
        if ((_loc.Y+1)<= K_MAX_ROWS)
            _loc.Y+=1;
        break;
    case dir::LEFT_DIR:
        if((_loc.X-1)>0)
            _loc.X-=1;
        break;
    case dir::RIGHT_DIR:
        if((_loc.X+1)<= K_MAX_COLS)
            _loc.X+=1;
        break;
    
    default:
        break;
    }
}

void Box::moveBox()
{
    switch (_direction)
    {
    case dir::UP_DIR:
        if ((_loc.Y-1)> 0)
            _loc.Y-=1;
        break;
    case dir::DOWN_DIR:
        if ((_loc.Y+1)<= K_MAX_ROWS)
            _loc.Y+=1;
        break;
    case dir::LEFT_DIR:
        if((_loc.X-1)>0)
            _loc.X-=1;
        break;
    case dir::RIGHT_DIR:
        if((_loc.X+1)<= K_MAX_COLS)
            _loc.X+=1;
        break;
    
    default:
        break;
    }
}

bool Box::isHead()
{
    return _isHead;
}

Point Box::getLocation()
{
    return _loc;
}



Box& Box::operator=(const Box& box)
{
    this->_B = box._B;
    this->_direction = box._direction;
    this->_G = box._G;
    this->_isHead = box._isHead;
    this->_R = box._R;
    this->_loc.X = box._loc.X;
    this->_loc.Y = box._loc.Y;

    return *this;        
}


void Box::updateLocation(Point loc)
{
    //TODO: Check range
    _loc.X = loc.X;
    _loc.Y = loc.Y;
}
void Box::updateDirection(dir dirctn)
{
    //TODO:: Check Range
    _direction = dirctn;
}

dir Box::getDirection()
{
    return _direction;
}