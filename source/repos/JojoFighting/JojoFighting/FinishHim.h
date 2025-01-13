#pragma once

#include <SFML/Graphics.hpp>

class FinishHim
{
public:
	FinishHim(sf::Vector2u windowSize);
	~FinishHim();

	sf::Text getText();
	void setText(std::string newText);

private:
	sf::Text text;
	sf::Font font;
	sf::Vector2u windowSize;
};