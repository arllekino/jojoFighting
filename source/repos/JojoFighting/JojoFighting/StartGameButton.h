#pragma once

#include <SFML/Graphics.hpp>

class StartGameButton
{
public:
	StartGameButton();
	~StartGameButton();

	void setPosition(sf::Vector2f position);
	sf::Vector2f getSize();
	sf::RectangleShape getButtonAsRect();
	sf::Text getPlaceholderText();
	void makeButtonHovered();
	void makeButtonUnhovered();

private:
	const std::string placeholderStartGame = "Start game";
	const sf::Vector2f buttonSize = sf::Vector2f(200, 100);
	const sf::Color buttonColor = sf::Color(133, 64, 178);

	sf::RectangleShape rect;
	sf::Text text;
	sf::Font font;
};
