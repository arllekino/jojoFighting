#pragma once

#include <SFML/Graphics.hpp>

class UltComponent
{
public:
	UltComponent(sf::Vector2f startPos, int direction);
	~UltComponent();

	sf::RectangleShape getAsShape();
	sf::RectangleShape getWrapperAsShape();
	void check(float readiness);
	void reset();

private:
	const sf::Vector2f startSize = { 300, 15 };
	
	sf::RectangleShape wrapper;
	sf::RectangleShape shape;
};