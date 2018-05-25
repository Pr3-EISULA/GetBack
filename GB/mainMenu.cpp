#include "mainMenu.hpp"

mainMenu::mainMenu()
{
  if (!texture.loadFromFile("mainMenu.png"));

  sprite.setTexture(texture);
}

//Logica del juego...
void mainMenu::update()
{
  
  //Que hacer cuando se presione y suelte el click izq del mouse
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    std::cout << "Click izquierdo presionado :)" << std::endl;
    std::cout << sf::Mouse::getPosition().x << " - ";
    std::cout << sf::Mouse::getPosition().y << std::endl;
    showMainMenu = false;
  }

}