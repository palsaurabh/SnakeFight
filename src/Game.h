#ifndef GAME_H
#define GAME_H

#include <random>
#include "Food.h"
#include "Snake.h"
#include "Renderer.h"
#include "Controller.h"

enum class GameMode {EATING_MODE, FIGHTING_MODE, OVER_MODE};
class Game
{
    public:
        std::vector<Snake> players;

        Game(int num_players = 1): _numPlayers{num_players}
        {
            if(_numPlayers > K_MAX_NUM_PLAYERS)
            {
                _numPlayers = K_MAX_NUM_PLAYERS;
            }
            for(int i = 0; i < num_players; i++)
            {
                players.emplace_back(Snake(getRandomNumber((K_GRIDWIDTH/2 - 2), (K_GRIDWIDTH/2 + 2)), 
                                            getRandomNumber((K_GRIDHEIGHT/2 - 2), (K_GRIDHEIGHT/2 + 2)),
                                            getRandomNumber(0, 255)));
            }
            loop = true;
            generateFood();
            mode = GameMode::EATING_MODE;
        }
        void update(dir *newDir);
        Food& getFood();
        void generateFood();
        void Loop(const Controller &controller, Renderer &renderer, std::size_t target_frame_duration);
        dir CheckDirection(Snake &snake, dir input) const;
        dir GetOppDirection(dir input) const ;
    private:
        Point getUnoccupiedLocation();
        int getRandomNumber(int lowerRange, int higherRange);
        // bool _isMultiplayer;
        int _numPlayers{1};
        Food food;
        bool loop;
        GameMode mode;
};


#endif /*GAME_H*/