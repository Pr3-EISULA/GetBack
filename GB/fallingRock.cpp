#include "fallingRock.hpp"

fallingRock::fallingRock()
{
    sprite.setTextureRect(sf::IntRect( 0, 0, 16, 16));
    size = 1 + rand()%5;
    rect.setScale( size, size);
    sprite.setScale( rect.getScale() );
    sprite.setPosition( 100 + rand()%700, rand()%300 - 300);
}

void fallingRock::updatePosition()
{
  sprite.move(0, moveSpeed);
  sprite.rotate(8);
  if ( sprite.getPosition().y > 550 )
  {
    moveSpeed += rand()%4 - 2;
    if (moveSpeed < moveSpeed - 5 || moveSpeed > moveSpeed + 10)
      moveSpeed = baseMoveSpeed;

    size = 1 + rand()%5;
    sprite.setScale( size, size );
    sprite.setPosition( 50 + rand()%700, rand()%300 - 300);
  }

}