#include <iostream>
#include "Game.h"

int main()
{
  // Create the renderer
  Renderer renderer(K_SCREENWIDTH, K_SCREENHEIGHT, K_GRIDWIDTH, K_GRIDHEIGHT);

  //Create the controller
  Controller controller;
  // Game game;

  //Initialise the game for 2 players
  Game game(2);

  //Start the game loop
  game.Loop(controller, renderer, K_MSPERFRAME);
  std::cout << "Game has terminated successfully!\n";
  //   std::cout << "Score: " << game.GetScore() << "\n";
  //   std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}