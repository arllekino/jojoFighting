#pragma once

#include <SFML/Graphics.hpp>

class HealthBarCharacter
{
public:
	HealthBarCharacter(sf::Vector2f position, int xScale);
	~HealthBarCharacter();

	sf::RectangleShape getHealthBarAsRect();
	sf::RectangleShape getWrapperAsRect();

	void setProgress(int hp, const int maxHp);

private:
	const sf::Color rectColor = sf::Color::Green;
	const sf::Vector2f rectSize = sf::Vector2f(750, 50);
	sf::RectangleShape rect;
	sf::RectangleShape wrapper;
};