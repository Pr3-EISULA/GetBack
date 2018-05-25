#ifndef FALLING_ROCK_HPP
#define FALLING_ROCK_HPP

#include <cmath>

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class fallingRock: public entity
{
public:
  int baseMoveSpeed = 13;
  int moveSpeed = baseMoveSpeed;
  int size;
  int rockSprite;

  fallingRock();
  void updatePosition();
};

#endif