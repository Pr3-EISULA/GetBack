//Use this for compiling
/*
g++ -std=c++11 -c main.cpp mainMenu.cpp entity.cpp player.cpp fallingRock.cpp
g++ main.o mainMenu.o entity.o player.o fallingRock.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
*/

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

#include "mainMenu.hpp"
#include "gameOver.hpp"
#include "victory.hpp"
#include "firstFRArea.hpp"
#include "secondFRArea.hpp"
#include "fallingRock.hpp"
#include "FBArea.hpp"
#include "flyingBat.hpp"
#include "player.hpp"
#include "entity.hpp"
#include "Collision.hpp"

int main()
{
    int counter = 0;

    sf::RenderWindow window( sf::VideoMode(800,600), "Test Window");
    window.setPosition(sf::Vector2i(300,200));
    window.setFramerateLimit(30);

    sf::Event event;

/////////////////////////////////////////////////////////////////////////////
// I HAVE TO DO THIS OR THE SPRITE WONT APPEAR ON MY VIRTUAL MAHCINE
// NOT NECESARY IF YOU ARE NOT USING VIRTUAL MACHINE    
    player *p2 = new player;
    if ( !p2->texture.loadFromFile("player-walking-2.png"))
      cout << "ERROR LOADING PLAYER TEXTURE" << endl;

    p2->sprite.setTexture(p2->texture);
    p2->sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    window.clear();
    window.draw(p2->sprite);
    window.display();
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

    // Outside world textures and sprites
    sf::Texture worldBackgroundTexture;
    worldBackgroundTexture.loadFromFile("worldBackground.png");
    sf::Sprite WorldBackgorundSprite;
    WorldBackgorundSprite.setTexture(worldBackgroundTexture);
    WorldBackgorundSprite.setScale(2.f, 2.f);

    sf::Texture worldWallsTexture;
    Collision::CreateTextureAndBitmask(worldWallsTexture, "worldWalls.png");
    sf::Sprite worldWallsSprite;
    worldWallsSprite.setTexture(worldWallsTexture);
    worldWallsSprite.setScale(2.f, 2.f);

    sf::Texture caveTriggerTexture;
    Collision::CreateTextureAndBitmask(caveTriggerTexture,"caveTrigger.png");
    sf::Sprite caveTriggerSprite;
    caveTriggerSprite.setTexture(caveTriggerTexture);
    caveTriggerSprite.setScale(2.f, 2.f);

    bool showWorld = true;

    // Cave texture and sprites
    sf::Texture caveBackgroundTexture;
    Collision::CreateTextureAndBitmask(caveBackgroundTexture, "caveBackground.png");
    sf::Sprite caveBackgroundSprite;
    caveBackgroundSprite.setTexture(caveBackgroundTexture);
    caveBackgroundSprite.setScale(2.f, 2.f);

    sf::Texture caveWallsTexture;
    Collision::CreateTextureAndBitmask(caveWallsTexture, "caveWalls.png");
    sf::Sprite caveWallsSprite;
    caveWallsSprite.setTexture(caveWallsTexture);
    caveWallsSprite.setScale(2.f, 2.f);

    sf::Texture caveHolesTexture;
    Collision::CreateTextureAndBitmask(caveHolesTexture, "caveHoles.png");
    sf::Sprite caveHolesSprite;
    caveHolesSprite.setTexture(caveHolesTexture);
    caveHolesSprite.setScale(2.f, 2.f);

    sf::Texture worldTriggerTexture;
    Collision::CreateTextureAndBitmask(worldTriggerTexture,"worldTrigger.png");
    sf::Sprite worldTriggerSprite;
    worldTriggerSprite.setTexture(worldTriggerTexture);
    worldTriggerSprite.setScale(2.f, 2.f);

    bool showCave = false;

    sf::Texture winTriggerTexture;
    Collision::CreateTextureAndBitmask(winTriggerTexture,"winTrigger.png");
    sf::Sprite winTriggerSprite;
    winTriggerSprite.setTexture(winTriggerTexture);
    winTriggerSprite.setScale(2.f, 2.f);

    mainMenu MMenu;
    gameOver GOver;
    victory vic;

    // Player creation
    player *p1 = new player;

    //Starting position of the player
    p1->rect.setPosition(300,700);
    p1->rect.setScale(0.5, 0.5);

    // Main view
    sf::View view;
    view.setViewport(sf::FloatRect(0,0,1,1));

    // Falling Rocks areas
    firstFRArea FRA1;
    secondFRArea FRA2;

    // Flying bats area
    FBArea FBA;

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
            case sf::Event::MouseButtonPressed:  
              cout << sf::Mouse::getPosition().x << endl;
              break;

          }
        }

        // Refresh the window
        window.clear();

        //TO CONTROL THE CAMERA ZOOM
        if ( MMenu.showMainMenu )
        {
          
          view.reset(sf::FloatRect(0, 0, 800, 600));

          if (MMenu.newGame)
          {
            delete p1;
            p1 = new player;
            cout << "new game created" << endl;
            p1->rect.setPosition(300,700);
            p1->rect.setScale(0.5, 0.5);
            MMenu.newGame = false;
          }
          MMenu.update();
        }
        else
        {
          // When something causes the player to die
          if ( GOver.showGameOver )
          {
            GOver.rect.setOrigin( p1->rect.getPosition() );
            GOver.text.setPosition( view.getCenter().x - 120,
                                    view.getCenter().y - 116 );
            // When 'm' is pressed
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::M) )
            {
              GOver.showGameOver = false;
              GOver.mainMenu = false;
              p1->gameOver = true;
            }
            // When 'c' is pressed
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::C) )
            {
              GOver.showGameOver = false;
              delete p1;
              p1 = new player;
              cout << "new game created" << endl;
              p1->rect.setPosition(300,700);
              p1->rect.setScale(0.5, 0.5);
              GOver.continueGame = false;
            }
            GOver.update();
            p1->canMoveUp = true;
            p1->canMoveDown = true;
            p1->canMoveRight = true;
            p1->canMoveLeft = true;
          }
          // Whenever the player is alive
          else
          {
            // Call Main menu when player dies and selects main menu option
            if ( p1->gameOver )
            {
              MMenu.showMainMenu = true;
            }

            // Center the view on the player
            view.reset( sf::FloatRect( p1->rect.getPosition().x - 200,
                                    p1->rect.getPosition().y - 150,
                                    400,
                                    300));
            // If player is near bounds of the map, stop camera movement
            if( view.getCenter().x < 200)
              view.setCenter(200, view.getCenter().y);
            if( view.getCenter().x > 2470)
              view.setCenter(2470, view.getCenter().y);
            if( view.getCenter().y < 150)
              view.setCenter(view.getCenter().x, 150);
            if( view.getCenter().y > 1962)
              view.setCenter(view.getCenter().x, 1962);
            
            // When player is outside in the forest
            if ( showWorld )
            {
              GOver.rect.setScale( 40, 40 );
              vic.rect.setScale( 40, 40);
              vic.text.setPosition( p1->rect.getPosition().x - 180,
                                    p1->rect.getPosition().y - 68 );

              // Check collision with obstacles(walls, trees, etc...)
              if (Collision::PixelPerfectTest(p1->sprite, worldWallsSprite))
              {
                p1->moveSpeed = 0;
                std::cout << "Collided" << std::endl;
                if (p1->direction == 1) // Up
                {
                  p1->canMoveUp = false;
                  p1->canMoveRight = false;
                  p1->canMoveLeft = false;
                  p1->rect.move(0,p1->baseMoveSpeed);
                }
                else if (p1->direction == 2) // Down
                {
                  p1->canMoveDown = false;
                  p1->canMoveRight = false;
                  p1->canMoveLeft = false;
                  p1->rect.move(0,-p1->baseMoveSpeed);
                }
                else if (p1->direction == 3) // Right
                {
                  p1->canMoveUp = false;
                  p1->canMoveDown = false;
                  p1->canMoveRight = false;
                  p1->rect.move(-p1->baseMoveSpeed,0);
                }
                else if (p1->direction == 4) // Left
                {
                  p1->canMoveUp = false;
                  p1->canMoveDown = false;
                  p1->canMoveLeft = false;
                  p1->rect.move(p1->baseMoveSpeed,0);
                }
              }
              else
                p1->moveSpeed = p1->baseMoveSpeed;

              // Check rock collitions for falling rocks in area 1
              counter = 0;
              for (FRA1.iter = FRA1.rockArray.begin(); FRA1.iter != FRA1.rockArray.end(); FRA1.iter++)
              {
                if (Collision::PixelPerfectTest(p1->sprite, FRA1.rockArray[counter].sprite))
                {
                  std::cout << "ouch" << counter << std::endl;
                  GOver.showGameOver = true;
                }
                counter++;
              }
              // Check rock collitions for falling rocks in area 2
              counter = 0;
              for (FRA2.iter = FRA2.rockArray.begin(); FRA2.iter != FRA2.rockArray.end(); FRA2.iter++)
              {
                if (Collision::PixelPerfectTest(p1->sprite, FRA2.rockArray[counter].sprite))
                {
                  std::cout << "ouch" << counter << std::endl;
                  GOver.showGameOver = true;
                }
                counter++;
              }

              // When the player is 1 rectangle inside the cave
              if (Collision::PixelPerfectTest(p1->sprite, caveTriggerSprite))
              {
                showCave = true;
                showWorld = false;
              }

              if (Collision::PixelPerfectTest(p1->sprite, winTriggerSprite))
              {
                vic.showVictory = true;
                
              }

            }
            if ( showCave )
            {
              // Check collision with cave walls
              if (Collision::PixelPerfectTest(p1->sprite, caveWallsSprite))
              {
                p1->moveSpeed = 0;
                std::cout << "Collided" << std::endl;
                if (p1->direction == 1) // Up
                {
                  p1->canMoveUp = false;
                  p1->canMoveRight = false;
                  p1->canMoveLeft = false;
                  p1->rect.move(0,p1->baseMoveSpeed);
                }
                else if (p1->direction == 2) // Down
                {
                  p1->canMoveDown = false;
                  p1->canMoveRight = false;
                  p1->canMoveLeft = false;
                  p1->rect.move(0,-p1->baseMoveSpeed*3);
                }
                else if (p1->direction == 3) // Right
                {
                  p1->canMoveUp = false;
                  p1->canMoveDown = false;
                  p1->canMoveRight = false;
                  p1->rect.move(-p1->baseMoveSpeed,0);
                }
                else if (p1->direction == 4) // Left
                {
                  p1->canMoveUp = false;
                  p1->canMoveDown = false;
                  p1->canMoveLeft = false;
                  p1->rect.move(p1->baseMoveSpeed,0);
                }
              }
              else
                p1->moveSpeed = p1->baseMoveSpeed;

              // Check for collision with bats
              counter = 0;
              for (FBA.iter = FBA.batArray.begin(); FBA.iter != FBA.batArray.end(); FBA.iter++)
              {
                if (Collision::PixelPerfectTest(p1->sprite, FBA.batArray[counter].sprite))
                {
                  std::cout << "ouch" << counter << std::endl;
                  p1->rect.move(0,1);
                }
                counter++;
              }

              if (Collision::PixelPerfectTest(p1->sprite, caveHolesSprite))
              {
                GOver.showGameOver = true;
              }

              // When the player is 1 rectangle outside the cave
              if ( !Collision::PixelPerfectTest(p1->sprite, caveBackgroundSprite) ||
                    Collision::PixelPerfectTest(p1->sprite, worldTriggerSprite) )
              {
                showWorld = true;
                showCave = false;
              }
            }

            // Update the player position according to keyboard inputs
            p1->update();
          }
        }

        window.setView(view);

        /////////////////////////
        // DRAWING THE SPRITES //
        /////////////////////////
  
        // Keeps the bats moving
        FBA.update();

        // When player is inside the cave
        if ( showCave )
        {
          std::cout << "in cave " << std::endl;
          window.draw(caveBackgroundSprite);
          window.draw(caveHolesSprite);
          window.draw(caveWallsSprite);

          // Draw bats
          counter = 0;
          for (FBA.iter = FBA.batArray.begin(); FBA.iter != FBA.batArray.end(); FBA.iter++)
          {
              FBA.batArray[counter].update();
              window.draw(FBA.batArray[counter].sprite2);
              window.draw(FBA.batArray[counter].sprite);
              counter++;
          }
        }

        // Keeps the rocks moving...
        FRA1.update();
        FRA2.update();

        // When player is in the outside world
        if ( showWorld )
        {
        //  std::cout << "in world " << std::endl;
          // Draw the outside background
          window.draw(WorldBackgorundSprite);
          window.draw(worldWallsSprite);

          // Draw and update falling rocks from first area
          counter = 0;
          for (FRA1.iter = FRA1.rockArray.begin(); FRA1.iter != FRA1.rockArray.end(); FRA1.iter++)
          {
              FRA1.rockArray[counter].update();
              window.draw(FRA1.rockArray[counter].sprite);
              counter++;
          }

          // Draw and update falling rocks from second area
          counter = 0;
          for (FRA2.iter = FRA2.rockArray.begin(); FRA2.iter != FRA2.rockArray.end(); FRA2.iter++)
          {
              FRA2.rockArray[counter].update();
              window.draw(FRA2.rockArray[counter].sprite);
              counter++;
          }
        }       

        if ( !GOver.showGameOver )
        {
          window.draw(p1->sprite);
          window.draw(p1->topSprite);
        }

        if ( GOver.showGameOver )
        {
          GOver.sprite.setColor(sf::Color(255,255,255,125));
          window.draw(GOver.sprite);
          window.draw(GOver.text);
        }
        
        if ( vic.showVictory )
        {
          vic.sprite.setColor(sf::Color(255,255,50,180));
          window.draw(vic.sprite);
          window.draw(vic.text);
        }


        if( MMenu.showMainMenu )
        {
          window.draw(MMenu.sprite);
        }

        window.display();
    }

    return 0;
}
