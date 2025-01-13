#include "FinishHim.h"

#include <SFML/Graphics.hpp>

FinishHim::FinishHim(sf::Vector2u windowSize)
{
	font.loadFromFile("assets/game/fonts/Bangers-Regular.ttf");
	text.setFont(font);
	text.setString("FINISH HIM");
	text.setCharacterSize(50);
	auto textSize = text.getGlobalBounds().getSize();
	text.setPosition((windowSize.x - textSize.x) / 2, (windowSize.y - textSize.y) / 2);
	text.setFillColor(sf::Color::Yellow);
	this->windowSize = windowSize;
}

FinishHim::~FinishHim()
{
}

sf::Text FinishHim::getText()
{
	return text;
}

void FinishHim::setText(std::string newText)
{
	text.setString(newText);
	auto textSize = text.getGlobalBounds().getSize();
	text.setPosition((windowSize.x - textSize.x) / 2, (windowSize.y - textSize.y) / 2);
}