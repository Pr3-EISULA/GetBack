#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

#include "Collision.hpp"

class entity
{
public:
  sf::RectangleShape rect;
  sf::Texture texture, textureTest;
  sf::Sprite sprite;
  sf::Text text;


  entity();

};


#endif