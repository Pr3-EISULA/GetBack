#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class entity
{
public:
  sf::RectangleShape rect;
  sf::Texture texture;
  sf::Sprite sprite;


  entity();

};


#endif