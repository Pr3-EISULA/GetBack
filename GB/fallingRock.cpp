#include "fallingRock.hpp"

fallingRock::fallingRock()
{
  rect.setScale(2, 2);
  rect.setPosition( 944 + rand()%468, 420 );

  texture.loadFromFile("rollingRock.png");

  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect( 0, 0, 16, 16));
  sprite.setScale(rect.getScale());
  
}

void fallingRock::update()
{
  sprite.setPosition(rect.getPosition());
  sprite.setRotation(rect.getRotation());
  sprite.setScale(rect.getScale());
  sprite.setOrigin(8, 8);

  rect.move(0, moveSpeed);
  sprite.setTextureRect( sf::IntRect( 16*fallingAnimationFrame, 0, 16, 16));
  
  // Change the spriteframe every 10 gameframes
  frameCounter++;
  if (frameCounter > 9)
    frameCounter = 0;
  if(frameCounter%2 == 0)
    fallingAnimationFrame++;
  if (fallingAnimationFrame > 5)
    fallingAnimationFrame = 0;

  //rect.rotate(8);
}