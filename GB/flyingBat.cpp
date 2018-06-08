#include "flyingBat.hpp"

flyingBat::flyingBat()
{
  //rect.setScale(2, 2);
  rect.setPosition( 944 + rand()%468, 420 );

  Collision::CreateTextureAndBitmask(texture, "flyingBat.png");

  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect( 0, 0, 32, 32));
  sprite.setScale(rect.getScale());

  Collision::CreateTextureAndBitmask(texture2, "flyingBat.png");

  sprite2.setTexture(texture);
  sprite2.setTextureRect(sf::IntRect( 0, 0, 32, 32));
  sprite2.setScale(rect.getScale());
  
}

void flyingBat::update()
{
  sprite.setPosition(rect.getPosition());
  sprite.setScale(rect.getScale());
  sprite.setOrigin(16, 16);

  sprite2.setPosition(rect.getPosition());
  sprite2.setScale(rect.getScale());
  sprite2.setOrigin(16, 16);

  rect.move(0, moveSpeed);
  sprite.setTextureRect( sf::IntRect( 32*flyingAnimationFrame, 0, 32, 32));
  sprite2.setTextureRect( sf::IntRect( 32*flyingAnimationFrame, 0, 32, 32));
  
  // Change the spriteframe every 10 gameframes
  frameCounter++;
  if (frameCounter > 9)
    frameCounter = 0;
  if(frameCounter%2 == 0)
    flyingAnimationFrame++;
  if (flyingAnimationFrame > 3)
    flyingAnimationFrame = 0;

  //rect.rotate(8);
}