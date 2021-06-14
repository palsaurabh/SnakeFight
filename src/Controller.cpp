#include "Controller.h"
#include <iostream>
#include "Snake.h"

//Handle input coming from keyboard and window close button
void Controller::HandleInput(bool &running, dir *newDir) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
      case SDLK_UP: //Player 1
        newDir[0] = dir::UP_DIR;
        break;

      case SDLK_DOWN: //Player 1
        newDir[0] = dir::DOWN_DIR;
        break;

      case SDLK_LEFT: //Player 1
        newDir[0] = dir::LEFT_DIR;
        break;

      case SDLK_RIGHT: //Player 1
        newDir[0] = dir::RIGHT_DIR;
        break;
      case SDLK_w: //Player 2
        newDir[1] = dir::UP_DIR;
        break;

      case SDLK_s: //Player 2
        newDir[1] = dir::DOWN_DIR;
        break;

      case SDLK_a: //Player 2
        newDir[1] = dir::LEFT_DIR;
        break;

      case SDLK_d: //Player 2
        newDir[1] = dir::RIGHT_DIR;
        break;
      }
    }
  }
}