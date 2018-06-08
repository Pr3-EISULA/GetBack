#include "victory.hpp"

victory::victory()
{
  font.loadFromFile("Pixeled.ttf");
  rect.setFillColor(sf::Color::Yellow);

  texture.loadFromFile("black800x600.png");
  sprite.setTexture(texture);

  text.setFont(font);
  text.setColor(sf::Color::Yellow);
  text.setCharacterSize(25);
  text.setString("CONGRATULATIONS! \n  YOU MANAGED TO\n        GET BACK");
}

//Logica del juego...
void victory::update()
{
  sprite.setPosition(rect.getPosition());
  sprite.setScale(rect.getScale());
}