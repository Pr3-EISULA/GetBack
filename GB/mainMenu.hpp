#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class mainMenu: public entity
{
public:
  bool showMainMenu = true;
  sf::Vertex A, B, C, D;
  sf::Vertex E, F, G, H;

  mainMenu();
  void update();
};
#endif