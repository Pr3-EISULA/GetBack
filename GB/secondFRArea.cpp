#include "secondFRArea.hpp"

secondFRArea::secondFRArea()
{
  rect.setPosition( 900, 420);

  rock.baseMoveSpeed = 10;
  for (int i = 0; i < numberOfRocks; i++)
  {
    rock.rect.setPosition( 1476 + 48*i, 452 - 96*i );
    rockArray.push_back(rock);
  }
}

void secondFRArea::update()
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
        rockArray[counter].baseMoveSpeed = 10;
        rockArray[counter].moveSpeed = rockArray[counter].baseMoveSpeed;
        rockArray[counter].rect.setPosition( 1476 + 48*counter, 452 );
      }
    counter++;
  }
}