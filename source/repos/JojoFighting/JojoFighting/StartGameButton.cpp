#include "StartGameButton.h"

#include <SFML/Graphics.hpp>

StartGameButton::StartGameButton()
{
	rect.setSize(buttonSize);
	rect.setFillColor(buttonColor);
	rect.setOutlineColor(sf::Color::Yellow);

	font.loadFromFile("assets/game/fonts/Bangers-Regular.ttf");
	text.setFont(font);
	text.setString(placeholderStartGame);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
}

StartGameButton::~StartGameButton()
{
}

void StartGameButton::setPosition(sf::Vector2f position)
{
	rect.setPosition(position);
	text.setPosition(position + sf::Vector2f(40, 30));
}

sf::RectangleShape StartGameButton::getButtonAsRect()
{
	return rect;
}

sf::Vector2f StartGameButton::getSize()
{
	return rect.getSize();
}

sf::Text StartGameButton::getPlaceholderText()
{
	return text;
}

void StartGameButton::makeButtonHovered()
{
	rect.setOutlineThickness(2);
}

void StartGameButton::makeButtonUnhovered()
{
	rect.setOutlineThickness(0);
}