#ifndef FBAREA_H
#define FBAREA_H

#include <SFML/Graphics.hpp>

#include "entity.hpp"
#include "flyingBat.hpp"

class FBArea: public entity
{
public:
  int counter;

  flyingBat bat;

  std::vector<flyingBat>::iterator iter;
  std::vector<flyingBat> batArray;
  FBArea();
  void update();
};

#endif