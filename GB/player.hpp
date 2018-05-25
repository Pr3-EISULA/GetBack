#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class player: public entity
{
public:
  int moveSpeed = 3;
  int counter = 0; 
  int walkingAnimationFrame = 1;

  player();
  void update();
  void updatePosition();

};
#endif
