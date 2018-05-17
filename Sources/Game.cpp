#include "Game.h"
#include <iostream>

Game::Game(): ventana(sf::VideoMode(800, 600), "window1")
{

}

int Game::inicializar()
{
	//Velocidad de los FPS
	ventana.setFramerateLimit(60);

	//sprite del personaje 1
	if (!miTextura.loadFromFile("p1_N.PNG"))
		return 1;
	miSprite.setTexture(miTextura);
	miSprite.setPosition(400, 500);
	miSprite.setOrigin(miSprite.getLocalBounds().width/2.f, miSprite.getLocalBounds().height/2.f);

	//Sprite del background 1
	if (!miTextura2.loadFromFile("bg1.PNG"))
		return 1;
	miSprite2.setTexture(miTextura2);

	//Sprite de la entrada a la cueva
	if (!miTextura3.loadFromFile("caveEntrance.PNG"))
		return 1;
	miSprite3.setTexture(miTextura3);
}

void Game::eventos()
{
	//Gameloop...
	while (ventana.pollEvent(miEvento)) {
		//Terminar ejecucion cuando se cierre "ventana"...
		if (miEvento.type == sf::Event::Closed)
			isPlay = false;

		//KeyPressed
		if (miEvento.type == sf::Event::KeyPressed && 
			miEvento.key.code == sf::Keyboard::W)
			pressedUP = true;

		if (miEvento.type == sf::Event::KeyPressed && 
			miEvento.key.code == sf::Keyboard::S)
			pressedDOWN = true;

		if (miEvento.type == sf::Event::KeyPressed && 
			miEvento.key.code == sf::Keyboard::D)
			pressedRIGHT = true;

		if (miEvento.type == sf::Event::KeyPressed && 
			miEvento.key.code == sf::Keyboard::A)
			pressedLEFT = true;

		//KeyReleased
		if (miEvento.type == sf::Event::KeyReleased && 
			miEvento.key.code == sf::Keyboard::W)
			pressedUP = false;

		if (miEvento.type == sf::Event::KeyReleased && 
			miEvento.key.code == sf::Keyboard::S)
			pressedDOWN = false;

		if (miEvento.type == sf::Event::KeyReleased && 
			miEvento.key.code == sf::Keyboard::D)
			pressedRIGHT = false;

		if (miEvento.type == sf::Event::KeyReleased && 
			miEvento.key.code == sf::Keyboard::A)
			pressedLEFT = false;

		//LeftCLick pressed
		if (miEvento.type == sf::Event::MouseButtonPressed && miEvento.mouseButton.button == sf::Mouse::Left)
			leftClick = true;
		//Mouse Position Detection
		if (miEvento.type == sf::Event::MouseMoved) {
			mouseX = miEvento.mouseMove.x;
			mouseY = miEvento.mouseMove.y;
		}

	}
}

//Logica del juego...
void Game::update()
{
	//Logica de movimiento
	if (pressedUP) {
		if (pressedRIGHT) {
			miSprite.setRotation(-315);
			std::cout << "W y D presionado" << std::endl;
			miSprite.move(3, -3);
		}
		else if (pressedLEFT) {
			miSprite.setRotation(-45);
			std::cout << "W y A presionado" << std::endl;
			miSprite.move(-3, -3);
		}
		else {
			miSprite.setRotation(0);
			std::cout << "W presionado" << std::endl;
			miSprite.move(0, -3);
		}
	}
	if (pressedDOWN) {
		if (pressedRIGHT) {
			miSprite.setRotation(-225);
			std::cout << "W y D presionado" << std::endl;
			miSprite.move(3, 3);
		}
		else if (pressedLEFT) {
			miSprite.setRotation(-135);
			std::cout << "W y A presionado" << std::endl;
			miSprite.move(-3, 3);
		}
		else {
			miSprite.setRotation(-180);
			std::cout << "W presionado" << std::endl;
			miSprite.move(0, 3);
		}
	}
	if (pressedRIGHT && !pressedUP && !pressedDOWN) {
		miSprite.setRotation(-270);
		std::cout << "D presionado" << std::endl;
		miSprite.move(3, 0);
	}

	if (pressedLEFT && !pressedUP && !pressedDOWN) {
		miSprite.setRotation(-90);
		std::cout << "A presionado" << std::endl;
		miSprite.move(-3, 0);
	}

	//Que hacer cuando se presione y suelte el click izq del mouse
	if (leftClick) {
		std::cout << mouseX << " - " << mouseY << std::endl;
		leftClick = false;
	}

	//si entra a la cueva...
	if (miSprite.getPosition().x > 500 &&
		miSprite.getPosition().x < 568 &&
		miSprite.getPosition().y < 40)
	{
		cleared();
		std::shared_ptr<MainMenu> miJuego(new MainMenu);
		miJuego->run();
	}

	//Si se va alrededor de la montana...
	if (miSprite.getPosition().y > 100 &&
		miSprite.getPosition().y < 200 &&
		miSprite.getPosition().x < 40)
	{
		cleared();
		std::shared_ptr<MainMenu> miJuego(new MainMenu);
		miJuego->run();
	}

}

//Renderizado...
void Game::render()
{
	ventana.clear(sf::Color::Blue);

	ventana.draw(miSprite2);

	ventana.draw(miSprite);

	ventana.draw(miSprite3);

	ventana.display();
}

//Liberacion de memoria...
void Game::cleared()
{
	ventana.close();
}

void Game::run()
{
	inicializar();
	while (isPlay)
	{
		eventos();
		update();
		render();
	}
	cleared();
}
/*
https://www.youtube.com/watch?v=g5hFOANHjlQ
https://github.com/SFML/SFML/wiki/Source:-Simple-Collision-Detection-for-SFML-2
*/