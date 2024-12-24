#include <SFML/Window.hpp>

#include "JojoFightingMain.h"

#include "Game.h"
#include "GameState.h"

const int FRAME_LIMIT = 60;

void jojoFighting()
{
	sf::ContextSettings settings;
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "JojoFighting", sf::Style::Fullscreen, settings);
	window.setFramerateLimit(FRAME_LIMIT);

	auto game = Game{window.getSize()};

	while (window.isOpen())
	{
		switch (game.getGameState())
		{
		case GameState::menu:
			game.menu(window);
			break;
		case GameState::game:
			game.main(window);
			break;
		default:
			break;
		}
	}
}