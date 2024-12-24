#pragma once

#include <SFML/Graphics.hpp>

class Knife
{
public:
	Knife();
	~Knife();

	sf::RectangleShape getAsShape();
	void setPosition(sf::Vector2f newPos);

private:
	const float scale = 3.f;
	const std::string path = "assets/dio/knife.png";

	sf::RectangleShape shape;

};