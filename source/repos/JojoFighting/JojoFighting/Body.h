#pragma once

#include <SFML/Graphics.hpp>

struct Body
{
	bool isDrawable = true;
	sf::RectangleShape bodyShape;
	sf::RectangleShape punchShape;
};