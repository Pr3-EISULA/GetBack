#include "player.hpp"

player::player()
{
  rect.setSize(sf::Vector2f(16,16));
  rect.setPosition(8,300);
  rect.setFillColor(sf::Color::Blue);
  sprite.setTextureRect(sf::IntRect( 0, 0, 16, 16));
}

void player::update()
{
  sprite.setPosition(rect.getPosition());
  sprite.setRotation(rect.getRotation());
  //sprite.setTextureRect(sf::IntRect(0,0,16,16));
}

void player::updatePosition()
{
  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) || 
       sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
  {
    rect.move(0, -moveSpeed);
    rect.setRotation(180);
    sprite.setTextureRect( sf::IntRect( 16 * walkingAnimationFrame, 0, 16, 16));
  }
  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) || 
       sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
  {
    rect.move(0, moveSpeed);
    rect.setRotation(0);
    sprite.setTextureRect( sf::IntRect( 16 * walkingAnimationFrame, 0, 16, 16));
  }
  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) || 
       sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
  {
    rect.move(moveSpeed, 0);
    rect.setRotation(270);
    sprite.setTextureRect( sf::IntRect( 16 * walkingAnimationFrame, 0, 16, 16));
  }
  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
       sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
  {
    rect.move(-moveSpeed, 0);
    rect.setRotation(90);
    sprite.setTextureRect( sf::IntRect( 16 * walkingAnimationFrame, 0, 16, 16));
  }

  if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up))&&
       (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
    rect.setRotation(225);
  if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up))&&
       (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
    rect.setRotation(135);
  if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Down))&&
       (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
    rect.setRotation(315);
  if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Down))&&
       (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
    rect.setRotation(45);
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    counter++;
    if (counter > 9)
      counter = 0;
    if(counter%10 == 0)
      walkingAnimationFrame++;

    if (walkingAnimationFrame > 2)
      walkingAnimationFrame = 1;
  }
  else
    sprite.setTextureRect(sf::IntRect( 0, 0, 16, 16));
  
  
}