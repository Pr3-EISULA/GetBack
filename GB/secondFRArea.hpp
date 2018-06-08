#ifndef SECONDFRAREA_H
#define SECONDFRAREA_H
#include <iostream>

#include <SFML/Graphics.hpp>

#include "entity.hpp"
#include "fallingRock.hpp"

class secondFRArea: public entity
{
public:
  int numberOfRocks = 15;
  int counter;

  fallingRock rock;

  std::vector<fallingRock>::iterator iter;
  std::vector<fallingRock> rockArray;
  secondFRArea();
  void update();
};

#endif