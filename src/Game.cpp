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