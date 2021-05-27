#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "Snake.h"


void Controller::HandleInput(bool &running, dir &newDir) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          newDir = dir::UP_DIR;
          break;

        case SDLK_DOWN:
          newDir = dir::DOWN_DIR;
          break;

        case SDLK_LEFT:
          newDir = dir::LEFT_DIR;
          break;

        case SDLK_RIGHT:
          newDir = dir::RIGHT_DIR;
          break;
      }
    }
  }
}