#include "firstFRArea.hpp"

firstFRArea::firstFRArea()
{
  rect.setPosition(600, 672);

  rockArray.push_back(rock);
  rockArray.push_back(rock);
  rockArray.push_back(rock);
  rockArray.push_back(rock);
  rockArray.push_back(rock);
}

void firstFRArea::update()
{
  counter = 0;
  for ( iter = rockArray.begin(); iter != rockArray.end(); iter++)
  {
    if ( !rockArray[counter].changedBaseSpeed &&
          rockArray[counter].rect.getPosition().y > 660)
    {
      rockArray[counter].moveSpeed -= 4;
      rockArray[counter].changedBaseSpeed = true;
    }
    if (rockArray[counter].rect.getPosition().y > 864)
      {
        rockArray[counter].changedBaseSpeed = false;
        rockArray[counter].baseMoveSpeed = 11;
        rockArray[counter].moveSpeed += 2 - rand()%4;
        if (rockArray[counter].moveSpeed < rockArray[counter].baseMoveSpeed - 2 ||
            rockArray[counter].moveSpeed > rockArray[counter].baseMoveSpeed + 3)
          rockArray[counter].moveSpeed = rockArray[counter].baseMoveSpeed;

        rockArray[counter].rect.setPosition( 944 + rand()%468, 420 );
      }
    counter++;
  }
}