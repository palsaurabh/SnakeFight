#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "Snake.h"
#include "Food.h"

//Renderer class definition
class Renderer
{
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(std::vector<Snake> &snake, Food &food);
  //Print window title during the game mode Eating Food
  void UpdateWindowTitle(int score1, int score2, int fps);
  //Print window title after game finished
  void UpdateWindowTitle(int player);

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif