#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Snake.h"

//Controller class for getting the inputs
class Controller
{
public:
  void HandleInput(bool &running, dir *newDir) const;
};

#endif