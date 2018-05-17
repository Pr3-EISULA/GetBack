#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "MainMenu.h"

int main()
{


	std::shared_ptr<MainMenu> miJuego(new MainMenu);
	miJuego->run();


	return 0;
}