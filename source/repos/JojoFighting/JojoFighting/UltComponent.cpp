#include "UltComponent.h"

UltComponent::UltComponent(sf::Vector2f startPos, int direction)
{
	wrapper.setPosition(startPos);
	wrapper.setSize(startSize);
	wrapper.setFillColor(sf::Color(0, 0, 0, 0));
	wrapper.setOutlineThickness(1);
	wrapper.setOutlineColor(sf::Color::White);
	wrapper.setScale(direction, 1);

	shape.setPosition(startPos);
	shape.setSize(startSize);
	shape.setFillColor(sf::Color::Green);
	shape.setScale(direction, 1);
}

UltComponent::~UltComponent()
{
}

sf::RectangleShape UltComponent::getAsShape()
{
	return shape;
}

sf::RectangleShape UltComponent::getWrapperAsShape()
{
	return wrapper;
}

void UltComponent::check(float readiness)
{
	auto scale = readiness < 1 ? readiness : 1.f;

	shape.setSize({ startSize.x * scale, startSize.y });
	if (scale >= 1)
		shape.setFillColor(sf::Color(128, 128, 255));
	else
		shape.setFillColor(sf::Color::Red);
}

void UltComponent::reset()
{
	auto prevSize = shape.getSize();
	shape.setSize({ 0, prevSize.y });
}