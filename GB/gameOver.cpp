#include "gameOver.hpp"

gameOver::gameOver()
{
  font.loadFromFile("Pixeled.ttf");
  rect.setFillColor(sf::Color::Black);

  texture.loadFromFile("black800x600.png");
  sprite.setTexture(texture);

  text.setFont(font);
  text.setColor(sf::Color::White);
  text.setCharacterSize(25);
  text.setString(" GAME OVER\n\n(C) ONTINUE\n(M) AIN MENU");
}

//Logica del juego...
void gameOver::update()
{
  sprite.setPosition(rect.getPosition());
  sprite.setScale(rect.getScale());
  //Que hacer cuando se presione y suelte el click izq del mouse
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
  {
    continueGame = true;
  }
  else
    continueGame = false;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
  {
    mainMenu = true;
  }
  else
    mainMenu = false;
}