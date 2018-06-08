#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "entity.hpp"

class player: public entity
{
public:
  bool inCave = false;
  bool inWorld = false;

  bool gameOver = false;

  bool updatable = true;

  bool canMoveUp = true;
  bool canMoveDown = true;
  bool canMoveRight = true;
  bool canMoveLeft = true;
  
  int direction = 1;
  ///////////////////////////////////////////
  // 1 = Up            5 = Up + Right      //
  // 2 = Down          6 = Down + Left     //
  // 3 = Right         7 = Down + Right    //
  // 4 = Left          8 = Up + Left       //
  //      1                 8   5          //
  //    4   3                              //
  //      2                 6   7          //
  ///////////////////////////////////////////
  int baseMoveSpeed = 4;
  int moveSpeed = baseMoveSpeed;

  int frameCounter = 0; 
  int walkingAnimationFrame = 1;

  sf::Texture topTexture;
  sf::Sprite topSprite;

  player();
  void update();

};
#endif