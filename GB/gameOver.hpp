#ifndef GAMEOVER_MENU_HPP
#define GAMEOVER_MENU_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class gameOver: public entity
{
public:
  sf::Font font;
  bool continueGame = false;
  bool mainMenu = false;
  
  bool showGameOver = false;
  sf::Vertex A, B, C, D;
  sf::Vertex E, F, G, H;

  gameOver();
  void update();
};
#endif