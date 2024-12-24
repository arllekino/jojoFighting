#include "Knife.h"

Knife::Knife()
{
	sf::Image image;
	image.loadFromFile(path);
	image.createMaskFromColor(sf::Color(128, 128, 255));

	sf::Texture texture;
	texture.loadFromImage(image);
	
	shape.setSize({ image.getSize().x * scale, image.getSize().y * scale });
}

Knife::~Knife()
{
}

sf::RectangleShape Knife::getAsShape()
{
	return shape;
}

void Knife::setPosition(sf::Vector2f newPos)
{
	shape.setPosition(newPos);
}