#include "HealthBarCharacter.h"

#include <iostream>

HealthBarCharacter::HealthBarCharacter(sf::Vector2f position, int xScale)
{
	rect.setSize(rectSize);
	rect.setFillColor(rectColor);
	rect.setPosition(position);
	rect.setScale(xScale, 1);

	wrapper.setSize(rectSize);
	wrapper.setPosition(position);
	wrapper.setScale(xScale, 1);
	wrapper.setOutlineThickness(2);
	wrapper.setFillColor(sf::Color(0, 0, 0, 256));
	wrapper.setOutlineColor(sf::Color(246, 207, 49));
}

HealthBarCharacter::~HealthBarCharacter()
{
}

sf::RectangleShape HealthBarCharacter::getHealthBarAsRect()
{
	return rect;
}

sf::RectangleShape HealthBarCharacter::getWrapperAsRect()
{
	return wrapper;
}

void HealthBarCharacter::setProgress(int hp, const int maxHp)
{
	rect.setSize(sf::Vector2f(float(hp) / float(maxHp) * rectSize.x, rectSize.y));
}