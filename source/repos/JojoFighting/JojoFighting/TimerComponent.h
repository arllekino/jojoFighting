#pragma once

#include <SFML/Graphics.hpp>

class TimerComponent
{
public:
	TimerComponent(sf::Vector2u windowSize);
	~TimerComponent();

	sf::CircleShape getTimerAsShape();
	sf::Text getTimeAsText();
	sf::Time getTime();
	void restartTimer();

private:
	const sf::Time maxTime = sf::seconds(100);
	const float radius = 50;

	sf::CircleShape shape;
	sf::Clock clock;
	sf::Font font;
	sf::Text text;
};