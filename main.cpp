#include <iostream>
#include "Game.h"

int main() {
  Renderer renderer(K_SCREENWIDTH, K_SCREENHEIGHT, K_GRIDWIDTH, K_GRIDHEIGHT);
  Controller controller;
  Game game;
  game.Loop(controller, renderer, K_MSPERFRAME);
  std::cout << "Game has terminated successfully!\n";
//   std::cout << "Score: " << game.GetScore() << "\n";
//   std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}