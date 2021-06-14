#include "Game.h"

GameMode Game::mode;
int Game::timeLeft;
std::mutex Game::mtx;

Game::~Game()
{
    SDL_RemoveTimer(fightModeTimerID);
}

void Game::modifyGameMode(GameMode mode)
{
    std::lock_guard<std::mutex> lck(mtx);
    Game::mode = mode;
}

GameMode Game::getGameMode()
{
    std::lock_guard<std::mutex> lck(mtx);
    return Game::mode;
}

int Game::getTimeLeft()
{
    std::lock_guard<std::mutex> lck(mtx);
    return timeLeft;
}

Uint32 Game::FightMode_TimerCallback(Uint32 interval, void *param)
{
    std::unique_lock<std::mutex> lck(mtx);
    timeLeft--;
    if(timeLeft <= 0)
    {   
        lck.unlock();
        modifyGameMode(GameMode::OVER_MODE);
        return 0;
    }
    lck.unlock();
    return interval;
}

int Game::getRandomNumber(int lowerRange, int higherRange)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> distr(lowerRange, higherRange);
    return distr(engine);
}

const Point Game::getUnoccupiedLocation()
{
    Point Pt;
    bool notfound = true;
    while (notfound)
    {
        notfound = false;
        Pt.X = getRandomNumber(0, K_GRIDWIDTH - 1);
        Pt.Y = getRandomNumber(0, K_GRIDHEIGHT - 1);

        for (auto &p : players)
        {
            for (int i = 0; i < p.getSnakeLen(); i++)
            {
                if (Pt.X == p.getSnakeBoxLocationAt(i).X && Pt.Y == p.getSnakeBoxLocationAt(i).Y)
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
    food.foodCount--;
}

const Food &Game::getFood()
{
    return food;
}

dir Game::GetOppDirection(dir input) const
{
    dir opposite = dir::NO_DIR;
    switch (input)
    {
    case dir::UP_DIR:
        opposite = dir::DOWN_DIR;
        break;
    case dir::DOWN_DIR:
        opposite = dir::UP_DIR;
        break;
    case dir::RIGHT_DIR:
        opposite = dir::LEFT_DIR;
        break;
    case dir::LEFT_DIR:
        opposite = dir::RIGHT_DIR;
        break;
    default:
        break;
    }

    return opposite;
}
dir Game::CheckDirection(const Snake &snake, const dir input) const
{
    dir opposite = dir::NO_DIR;
    opposite = GetOppDirection(input);
    if (snake.getSnakeDirection() != opposite || snake.getSnakeLen() == 1)
        return input;
    else
        return dir::NO_DIR;
}

void Game::update(dir *newDir)
{
    int i = 0;

    if (getGameMode() == GameMode::EATING_MODE)
    {
        for (auto &snake : players)
        {
            if (snake.alive)
            {
                if (food.getLocation().X == snake.getSnakeBoxLocationAt(0).X &&
                    food.getLocation().Y == snake.getSnakeBoxLocationAt(0).Y)
                {
                    food.Eaten = true;
                    snake.updateSnake(CheckDirection(snake, newDir[i]), true, false);
                }
                else
                {
                    snake.updateSnake(CheckDirection(snake, newDir[i]), false, false);
                }
            }
            i++;
        }
    }
    else if (getGameMode() == GameMode::FIGHTING_MODE)
    {
        // printf("Game Mode Fight!!\n");
        for (int count = 1; count < players.at(0).getSnakeLen(); count++)
        {
            if (players.at(0).getSnakeBoxLocationAt(count).X == players.at(1).getSnakeBoxLocationAt(0).X &&
                players.at(0).getSnakeBoxLocationAt(count).Y == players.at(1).getSnakeBoxLocationAt(0).Y)
            {
                players.at(0).updateSnake(dir::NO_DIR, false, true, count);
                break;
            }
        }

        for (int count = 1; count < players.at(1).getSnakeLen(); count++)
        {
            if (players.at(1).getSnakeBoxLocationAt(count).X == players.at(0).getSnakeBoxLocationAt(0).X &&
                players.at(1).getSnakeBoxLocationAt(count).Y == players.at(0).getSnakeBoxLocationAt(0).Y)
            {
                players.at(1).updateSnake(dir::NO_DIR, false, true, count);
                break;
            }
        }

        players.at(0).updateSnake(CheckDirection(players.at(0), newDir[0]), false);
        players.at(1).updateSnake(CheckDirection(players.at(1), newDir[1]), false);
    }

    if (food.Eaten)
    {
        generateFood();
        if (food.foodCount <= 0)
        {
            modifyGameMode(GameMode::FIGHTING_MODE);
            // Game::mode = GameMode::FIGHTING_MODE;
            fightModeTimerID = SDL_AddTimer(K_ONESEC, FightMode_TimerCallback, NULL);
            if(fightModeTimerID == 0)
            {
                std::cout<<"Error Adding Fight Timer: "<<fightModeTimerID<<'\n';
            }
        }
        food.Eaten = false;
    }

    if (!players.at(0).alive || !players.at(1).alive)
    {   
        modifyGameMode(GameMode::OVER_MODE);
    }
}

void Game::Loop(const Controller &controller, Renderer &renderer, std::size_t target_frame_duration)
{
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;

    dir newDir[2];
    while (loop)
    {
        frame_start = SDL_GetTicks();
        // Input, Update, Render - the main game loop.
        controller.HandleInput(loop, newDir);
        if (getGameMode() != GameMode::OVER_MODE)
        {
            update(newDir);
        }
        renderer.Render(players, food);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000)
        {
            if (getGameMode() == GameMode::EATING_MODE)
            {
                renderer.UpdateWindowTitle(players.at(0).getScore(), players.at(1).getScore(), food.foodCount, getTimeLeft(), frame_count);
            }
            else if(getGameMode() == GameMode::FIGHTING_MODE)
            {
                renderer.UpdateWindowTitle(players.at(0).getScore(), players.at(1).getScore(), food.foodCount, getTimeLeft(), frame_count);
            }
            else
            {
                int player = 0;
                if(!players.at(0).alive || !players.at(1).alive)
                {
                    player = players.at(0).alive ? 1 : 2;
                }
                else if(players.at(0).getScore() > players.at(1).getScore())
                {
                    player = 1;
                }
                else if(players.at(0).getScore() == players.at(1).getScore())
                {
                    player = 0;
                }
                else if(players.at(0).getScore() < players.at(1).getScore())
                {
                    player = 2;
                }
                renderer.UpdateWindowTitle(player);
            }
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration)
        {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}