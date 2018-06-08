#ifndef FLTING_BAT_HPP
#define FLTING_BAT_HPP

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class flyingBat: public entity
{
public:
  bool firstSpawn = true;
  bool changedBaseSpeed = false;
  int baseMoveSpeed = 8;
  int moveSpeed = baseMoveSpeed;
  int size;
  int frameCounter = 0;
  int flyingAnimationFrame = 0;

  sf::Texture texture2;
  sf::Sprite sprite2;

  flyingBat();
  void update();
};

#endif