#include "player.hpp"

player::player()
{
  rect.setSize(sf::Vector2f(40, 50));
  rect.setPosition(/*64*/500,640);

  Collision::CreateTextureAndBitmask(texture, "bottomHiker.png");

  sprite.setTexture(texture);
  sprite.setOrigin(20,25);
  sprite.setTextureRect(sf::IntRect( 0, 0, 40, 50));

  topTexture.loadFromFile("player-walking-2.png");

  topSprite.setTexture(topTexture);
  topSprite.setOrigin(20,25);
  topSprite.setTextureRect(sf::IntRect( 0, 0, 40, 50));
}

void player::update()
{
  sprite.setPosition(rect.getPosition());
  sprite.setScale(rect.getScale());

  topSprite.setPosition(rect.getPosition());
  topSprite.setScale(rect.getScale());
  moveSpeed = baseMoveSpeed;

  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
  {
    if (canMoveUp)
      {
        rect.move(0, -moveSpeed);
        direction = 1;

        canMoveUp = true;
        canMoveDown = true;
        canMoveLeft = true;
        canMoveRight = true;
      }
    sprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 150, 40, 50));
    topSprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 150, 40, 50));
  }
  else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
  {
    if (canMoveDown)
      {
        rect.move(0,moveSpeed);
        direction = 2;

        canMoveUp = true;
        canMoveDown = true;
        canMoveLeft = true;
        canMoveRight = true;
      }
    sprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 0, 40, 50));
    topSprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 0, 40, 50));
  }
  else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
  {
    if (canMoveRight)
      {
        rect.move(moveSpeed,0);
        direction = 3;
        
        canMoveUp = true;
        canMoveDown = true;
        canMoveLeft = true;
        canMoveRight = true;
      }
    sprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 100, 40, 50));
    topSprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 100, 40, 50));
  }
  else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
  {
    if (canMoveLeft)
      {
        rect.move(-moveSpeed,0);
        direction = 4;

        canMoveUp = true;
        canMoveDown = true;
        canMoveLeft = true;
        canMoveRight = true;
      }
    sprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 50, 40, 50));
    topSprite.setTextureRect( sf::IntRect( 40*walkingAnimationFrame, 50, 40, 50));
  }
  else
  {
    direction = 0;
  }
  
  if ( direction != 0)
  {
    // Change the spriteframe every 10 gameframes
    frameCounter++;
    if (frameCounter > 9)
      frameCounter = 0;
    if(frameCounter%10 == 0)
      walkingAnimationFrame++;

    if (walkingAnimationFrame > 3)
      walkingAnimationFrame = 0;
  }
  else
  {
    switch(direction)
    {
    case 1:
    case 8:
      sprite.setTextureRect( sf::IntRect( 0, 150, 40, 50));
      topSprite.setTextureRect( sf::IntRect( 0, 150, 40, 50));
      break;
    case 2:
    case 6:
    case 7:
      sprite.setTextureRect( sf::IntRect( 0, 0, 40, 50));
      topSprite.setTextureRect( sf::IntRect( 0, 0, 40, 50));
      break;
    case 3:
    case 5:
      sprite.setTextureRect( sf::IntRect( 0, 100, 40, 50));
      topSprite.setTextureRect( sf::IntRect( 0, 100, 40, 50));  
      break;
    case 4:
      sprite.setTextureRect( sf::IntRect( 0, 50, 40, 50));
      topSprite.setTextureRect( sf::IntRect( 0, 50, 40, 50));
      break;
    }
  }
  
  
}