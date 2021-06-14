#include "Renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

//Renderer function for rendering Snakes and food
void Renderer::Render(std::vector<Snake> &players, Food &food)
{
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0xFF, 0x00, 0xFF);
  block.x = food.getLocation().X * block.w;
  block.y = food.getLocation().Y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  // SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  int snakeNum = 0;
  for (auto &snake : players)
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (int i = 1; i < snake.getSnakeLen(); i++)
    {
      block.x = snake.getSnakeBoxLocationAt(i).X * block.w;
      block.y = snake.getSnakeBoxLocationAt(i).Y * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    // std::cerr<<"Head X: "<< snake.getSnakeBoxLocationAt(0).X << " Head Y: "<< snake.getSnakeBoxLocationAt(0).Y<<'\n';
    block.x = static_cast<int>(snake.getSnakeBoxLocationAt(0).X) * block.w;
    block.y = static_cast<int>(snake.getSnakeBoxLocationAt(0).Y) * block.h;
    if (snake.alive)
    {
      if (snakeNum == 0)
      {
        SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
      }
      else if (snakeNum == 1)
      {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0x00, 0xFF);
      }
    }
    else
    {
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    SDL_RenderFillRect(sdl_renderer, &block);
    snakeNum++;
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score1, int score2, int foodRemaining, int timeRemaining, int fps)
{
  // std::string title{"Snake Fight Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  std::string title{"Snake Fight Score: "};
  title += "P1: ";
  title += std::to_string(score1);
  title += "   P2: ";
  title += std::to_string(score2);
  title += "   Food: ";
  title += std::to_string(foodRemaining);
  if(timeRemaining >= K_MAX_FIGHTMODE_TIMER)
  {
    title += "   Time: ";
    title += "-- ";
  }
  else
  {
    title += "   Time: ";
    title += std::to_string(timeRemaining);
  }
  title += " FPS: ";
  title += std::to_string(fps);
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::UpdateWindowTitle(int player)
{
  // std::string title{"Snake Fight Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  std::string title{"Game Over!!!: "};
  if(player !=0)
  {
    title += "Player ";
    title += std::to_string(player);
    title += " Wins!!";
  }
  else
  {
    title += "Its a Draw!!!";
  }
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
