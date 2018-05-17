#pragma once
#include <SFML\Graphics.hpp>

#include "MainMenu.h"

using namespace sf;

class Game
{
private:
	sf::RenderWindow ventana;
	sf::Event miEvento;	//controla el evento

	sf::Texture miTextura;
	sf::Sprite miSprite;

	sf::Texture miTextura2;
	sf::Sprite miSprite2;

	sf::Texture miTextura3;
	sf::Sprite miSprite3;

	//controla el gameloop
	bool isPlay{ true };

	//Variable del movimiento del jugador
	bool pressedUP{ false };
	bool pressedDOWN{ false };
	bool pressedRIGHT{ false };
	bool pressedLEFT{ false };
	//Variables de eventos...
	bool leftClick{ false };

	int mouseX , mouseY;

	int inicializar();
	void eventos();
	void update(); //Gameloop, logica
	void render();
	void cleared();

public:
	Game();
	void run();
};