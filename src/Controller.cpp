#include "Controller.h"
#include <iostream>
#include "SDL.h"
#include "Snake.h"


void Controller::HandleInput(bool &running, dir *newDir) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          newDir[0] = dir::UP_DIR;
          break;

        case SDLK_DOWN:
          newDir[0] = dir::DOWN_DIR;
          break;

        case SDLK_LEFT:
          newDir[0] = dir::LEFT_DIR;
          break;

        case SDLK_RIGHT:
          newDir[0] = dir::RIGHT_DIR;
          break;
        case SDLK_w:
          newDir[1] = dir::UP_DIR;
          break;

        case SDLK_s:
          newDir[1] = dir::DOWN_DIR;
          break;

        case SDLK_a:
          newDir[1] = dir::LEFT_DIR;
          break;

        case SDLK_d:
          newDir[1] = dir::RIGHT_DIR;
          break;

      }
    }
  }
}