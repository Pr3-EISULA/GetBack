#include "FBArea.hpp"

FBArea::FBArea()
{
  rect.setPosition(600, 672);

  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
  batArray.push_back(bat);
}

void FBArea::update()
{
  counter = 0;
  for ( iter = batArray.begin(); iter != batArray.end(); iter++)
  {
    if ( !batArray[counter].changedBaseSpeed &&
          batArray[counter].rect.getPosition().y > 128)
    {
      batArray[counter].moveSpeed -= 3;
      batArray[counter].changedBaseSpeed = true;
    }
    if (batArray[counter].rect.getPosition().y > 580)
      {
        batArray[counter].changedBaseSpeed = false;
        batArray[counter].baseMoveSpeed = 8;
        batArray[counter].moveSpeed += 2 - rand()%4;
        if (batArray[counter].moveSpeed < batArray[counter].baseMoveSpeed - 2 ||
            batArray[counter].moveSpeed > batArray[counter].baseMoveSpeed + 3)
          batArray[counter].moveSpeed = batArray[counter].baseMoveSpeed;

        batArray[counter].rect.setPosition( 944 + rand()%2212, 64 + rand()%32 );
      }
    counter++;
  }
}