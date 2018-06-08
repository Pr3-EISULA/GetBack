#ifndef VICTORY_HPP
#define VICTORY_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class victory: public entity
{
public:
  sf::Font font;

  bool showVictory = false;

  victory();
  void update();
};
#endif