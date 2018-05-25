//Use this for compiling
/*
g++ -std=c++11 -c main.cpp mainMenu.cpp entity.cpp player.cpp fallingRock.cpp
g++ main.o mainMenu.o entity.o player.o fallingRock.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
*/

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

#include "mainMenu.hpp"
#include "fallingRock.hpp"
#include "player.hpp"
#include "entity.hpp"


bool collision(sf::Vector2f entity1, sf::Vector2f entity2)
{
  int diffX = entity1.x - entity2.x;
  int diffY = entity1.y - entity2.y;
  if ( (diffX>-16 && diffX<16) && (diffY>-16 && diffY<16))
    return true;
  return false;
}

int main()
{
    sf::RenderWindow window( sf::VideoMode(800,600), "Test Window");
    window.setPosition(sf::Vector2i(300,200));
    window.setFramerateLimit(60);

    sf::Event event;

/////////////////////////////////////////////////////////////////////
// I HAVE TO DO THIS OR THE SPRITE WONT APPEAR ON MY VIRTUAL MAHCINE
    player *p2 = new player;
    if ( !p2->texture.loadFromFile("player-walking-1.png"))
      cout << "ERROR LOADING PLAYER TEXTURE" << endl;

    p2->sprite.setTexture(p2->texture);
    p2->sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    window.clear();
    window.draw(p2->sprite);
    window.display();
/////////////////////////////////////////////////////////////////////

    mainMenu MMenu;

    // Player creation
    player *p1 = new player;
    if ( !p1->texture.loadFromFile("player-walking-1.png"))
      cout << "ERROR LOADING PLAYER TEXTURE" << endl;
    p1->sprite.setOrigin(8,8); //cambiar a "mitad de el sprite" con los limites locales
    p1->sprite.setTexture(p1->texture);
    p1->sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);


    // Main view
    //sf::View view;
    //view.setViewport(sf::FloatRect(0,0,1,1));

    // Rock 1
    fallingRock *rock1 = new fallingRock;
    if ( !rock1->texture.loadFromFile("rollingRock.png"))
      cout << "ERROR LOADING PLAYER TEXTURE" << endl;
    rock1->sprite.setOrigin(8,8); //cambiar a "mitad de el sprite" con los limites locales
    rock1->sprite.setTexture(rock1->texture);

    // Rock 2
    fallingRock *rock2 = new fallingRock;
    if ( !rock2->texture.loadFromFile("rollingRock.png"))
      cout << "ERROR LOADING PLAYER TEXTURE" << endl;
    rock2->sprite.setOrigin(8,8); //cambiar a "mitad de el sprite" con los limites locales
    rock2->sprite.setTexture(rock2->texture);

    // Rock 3
    fallingRock *rock3 = new fallingRock;
    if ( !rock3->texture.loadFromFile("rollingRock.png"))
      cout << "ERROR LOADING PLAYER TEXTURE" << endl;
    rock3->sprite.setOrigin(8,8); //cambiar a "mitad de el sprite" con los limites locales
    rock3->sprite.setTexture(rock3->texture);

    // Gameloop
    while (window.isOpen())
    {
        // Events
        while (window.pollEvent(event))
        {
          switch(event.type)
          {
            case sf::Event::Closed:
              window.close();
              break;
            case sf::Event::KeyPressed:
              if(event.key.code == sf::Keyboard::Escape)
                window.close();
              
              break;
          }
        }
/*  TO CONTROL THE CAMERA ZOOM
        if ( MMenu.showMainMenu )
          view.reset(sf::FloatRect(0, 0, 800, 600));
        else
          view.reset( sf::FloatRect( p1->rect.getPosition().x - 200,
                                  p1->rect.getPosition().y - 150,
                                  400,
                                  300));
*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
          delete p1;
          p1 = new player;
          cout << "player created" << endl;

          if ( !p1->texture.loadFromFile("player-walking-1.png"))
            cout << "ERROR LOADING PLAYER TEXTURE" << endl;

          p1->sprite.setOrigin(8,8); //cambiar a "mitad de el sprite" con los limites locales
          p1->sprite.setTexture(p1->texture);
          p1->sprite.setPosition(8,300);
        }

        if ( p1->rect.getPosition().x > 750 )
        {
          p1->rect.setPosition(8,300);
          MMenu.showMainMenu = true;
        }

        if (collision(p1->sprite.getPosition(),rock1->sprite.getPosition()))
        {
          p1->rect.setPosition(8,300);
          MMenu.showMainMenu = true;
          cout << " ouch 1" << endl;
        }
        if (collision(p1->sprite.getPosition(),rock2->sprite.getPosition()))
        {
          p1->rect.setPosition(8,300);
          MMenu.showMainMenu = true;
          cout << " ouch 2" << endl;
        }
        if (collision(p1->sprite.getPosition(),rock3->sprite.getPosition()))
        {
          p1->rect.setPosition(8,300);
          MMenu.showMainMenu = true;
          cout << " ouch 3" << endl;
        }

        window.clear();

        window.setView(view);

        p1->update();
        p1->updatePosition();
        rock1->updatePosition();
        rock2->updatePosition();
        rock3->updatePosition();
        MMenu.update();

        window.draw(p1->sprite);
        window.draw(rock1->sprite);
        window.draw(rock2->sprite);
        window.draw(rock3->sprite);

        if( MMenu.showMainMenu )
        {
          window.draw(MMenu.sprite);
        }

        window.display();
    }

    return 0;
}