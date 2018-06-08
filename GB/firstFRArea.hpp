#ifndef FIRSTFRAREA_H
#define FIRSTFRAREA_H

#include <SFML/Graphics.hpp>

#include "entity.hpp"
#include "fallingRock.hpp"

class firstFRArea: public entity
{
public:
  int counter;

  fallingRock rock;

  std::vector<fallingRock>::iterator iter;
  std::vector<fallingRock> rockArray;
  firstFRArea();
  void update();
};

#endif