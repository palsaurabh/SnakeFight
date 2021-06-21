#include "Box.h"

void Box::moveBox(dir newdirctn)
{
    switch (newdirctn)
    {
    case dir::UP_DIR:
        if ((_loc.Y - 1) >= 0)
            _loc.Y -= 1;
        else
            _loc.Y = K_GRIDHEIGHT - 1;
        break;
    case dir::DOWN_DIR:
        if ((_loc.Y + 1) < K_GRIDHEIGHT)
            _loc.Y += 1;
        else
            _loc.Y = 0;
        break;
    case dir::LEFT_DIR:
        if ((_loc.X - 1) >= 0)
            _loc.X -= 1;
        else
            _loc.X = K_GRIDWIDTH - 1;
        break;
    case dir::RIGHT_DIR:
        if ((_loc.X + 1) < K_GRIDWIDTH)
            _loc.X += 1;
        else
            _loc.X = 0;
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
        if ((_loc.Y - 1) >= 0)
            _loc.Y -= 1;
        else
            _loc.Y = K_GRIDHEIGHT - 1;
        break;
    case dir::DOWN_DIR:
        if ((_loc.Y + 1) < K_GRIDHEIGHT)
            _loc.Y += 1;
        else
            _loc.Y = 0;
        break;
    case dir::LEFT_DIR:
        if ((_loc.X - 1) >= 0)
            _loc.X -= 1;
        else
            _loc.X = K_GRIDWIDTH - 1;
        break;
    case dir::RIGHT_DIR:
        if ((_loc.X + 1) < K_GRIDWIDTH)
            _loc.X += 1;
        else
            _loc.X = 0;
        break;

    default:
        break;
    }
}

bool Box::isHead() const
{
    return _isHead;
}

Point Box::getLocation() const
{
    return _loc;
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

dir Box::getDirection() const
{
    return _direction;
}

bool Box::isOnCollisionCourseWith(Box box) const
{
    Box thisBox = *this;
    // Box otherBox = box;

    if(abs(thisBox.getLocation().X - box.getLocation().X) < 2 && abs(thisBox.getLocation().Y - box.getLocation().Y) < 2)
    {
        thisBox.moveBox();
        if(abs(thisBox.getLocation().X - box.getLocation().X) == 0 && abs(thisBox.getLocation().Y - box.getLocation().Y) == 0)
        {
            return true;
        }

    }
    return false;
}