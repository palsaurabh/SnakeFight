#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Snake.h"

class Controller {
 public:
  void HandleInput(bool &running, dir &newDir) const;
};

#endif