#ifndef GAME_H
#define GAME_H

#include <random>
#include "Snake.h"
#include "renderer.h"
#include "controller.h"


class Game
{
    public:
        std::vector<Snake> players;

        Game(bool multiplayer = false, int num_players = 1): _isMultiplayer{multiplayer}, _numPlayers{num_players}
        {
            if(_numPlayers > K_MAX_NUM_PLAYERS)
            {
                _numPlayers = K_MAX_NUM_PLAYERS;
            }
            for(int i = 0; i < num_players; i++)
            {
                players.emplace_back(Snake(getRandomNumber((K_MAX_COLS/2 - 2), (K_MAX_COLS/2 + 2)), 
                                            getRandomNumber((K_MAX_ROWS/2 - 2), (K_MAX_ROWS/2 + 2)),
                                            getRandomNumber(0, 255)));
            }
            loop = true;
        }
        void update(dir& newDir);
        Box& getFood();
        void generateFood();
        void Loop(const Controller &controller, Renderer &renderer, std::size_t target_frame_duration);
    private:
        Point getUnoccupiedLocation();
        int getRandomNumber(int lowerRange, int higherRange);
        bool _isMultiplayer;
        int _numPlayers{1};
        Box food;
        bool loop;
};


#endif /*GAME_H*/