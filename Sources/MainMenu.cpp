#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu() : MainMenuWindow(sf::VideoMode(800, 600), "Main Menu")
{

}

int MainMenu::inicializar()
{
	MainMenuWindow.setFramerateLimit(30);

	//Sprite del Menu Pricipal
	if (!MainMenuTexture.loadFromFile("MainMenuSprite1.PNG"))
		return 1;

	MainMenuSprite.setTexture(MainMenuTexture);
}

void MainMenu::eventos()
{
	//MainMenuloop...
	while (MainMenuWindow.pollEvent(MainMenuEvent)) {
		//Terminar ejecucion cuando se cierre "MainMenuWindow"...
		if (MainMenuEvent.type == sf::Event::Closed)
			isPlay = false;

		//LeftCLick pressed and released...
		if (MainMenuEvent.type == sf::Event::MouseButtonPressed && 
			MainMenuEvent.mouseButton.button == sf::Mouse::Left)
			leftClick = true;

		if (MainMenuEvent.type == sf::Event::MouseMoved) {
			mouseX = MainMenuEvent.mouseMove.x;
			mouseY = MainMenuEvent.mouseMove.y;
		}

	}
}

//Logica del juego...
void MainMenu::update()
{
	
	//Que hacer cuando se presione y suelte el click izq del mouse
	if (leftClick) {
		if (mouseX > 100 && mouseX < 400 && mouseY>200 && mouseY < 300) {
			cleared();
			std::shared_ptr<Game> miJuego(new Game);
			miJuego->run();
		}
		std::cout << "Click izquierdo presionado :)" << std::endl;
		std::cout << mouseX << " - " << mouseY << std::endl;
		leftClick = false;
	}

}

//Renderizado...
void MainMenu::render()
{
	MainMenuWindow.draw(MainMenuSprite);
	MainMenuWindow.display();
}

//Liberacion de memoria...
void MainMenu::cleared()
{
	MainMenuWindow.close();
}

void MainMenu::run()
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