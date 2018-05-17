#pragma once
#include <memory>

#include <SFML\Graphics.hpp>

#include "Game.h"

class MainMenu
{
private:
	sf::RenderWindow MainMenuWindow;
	sf::Event MainMenuEvent;

	sf::Texture MainMenuTexture;
	sf::Sprite MainMenuSprite;

	bool isPlay{ true };
	bool leftClick{ false };

	int mouseX, mouseY;

	int inicializar();
	void eventos();
	void update(); //Gameloop, logica
	void render();
	void cleared();

public:
	MainMenu();
	void run();
};