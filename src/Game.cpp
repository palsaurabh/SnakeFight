#include "Game.h"

int Game::getRandomNumber(int lowerRange, int higherRange)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> distr(lowerRange, higherRange);
    return distr(engine);
}

Point Game::getUnoccupiedLocation()
{
    Point Pt;
    bool notfound = true;
    while(notfound)
    {
        notfound = false;
        Pt.X = getRandomNumber(0, K_MAX_COLS - 1);
        Pt.Y = getRandomNumber(0, K_MAX_ROWS - 1);

        for(auto& p : players)
        {
            for(int i = 0; i < p.getSnakeLen(); i++)
            {
                if(Pt.X == p.getSnakeBoxLocationAt(i).X && Pt.Y == p.getSnakeBoxLocationAt(i).Y)
                {
                    notfound = true;
                    break;
                }
            }
        }    
    }

    return Pt;
}
void Game::generateFood()
{
    food.updateLocation(getUnoccupiedLocation());
}

Box& Game::getFood()
{
    return food;
}

void Game::update(dir& newDir)
{
    for(auto& snake : players)
    {
        if(snake.alive)
        {
            snake.updateSnake(newDir, false);
        }
    }
}

void Game::Loop(const Controller &controller, Renderer &renderer, std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  
  while (loop) {
    frame_start = SDL_GetTicks();
    dir newDir;
    // Input, Update, Render - the main game loop.
    controller.HandleInput(loop, newDir);
    update(newDir);
    renderer.Render(players, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(0, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }

}