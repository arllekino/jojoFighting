#include "TimerComponent.h"

TimerComponent::TimerComponent(sf::Vector2u windowSize)
{
    shape.setRadius(radius);
    shape.setPosition(windowSize.x / 2 - radius, 30);
    shape.setFillColor(sf::Color::Black);

    font.loadFromFile("assets/game/fonts/Bangers-Regular.ttf");
    text.setFont(font);
    text.setString(std::to_string(maxTime.asSeconds()));
    text.setCharacterSize(45);
    text.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = text.getLocalBounds();
    float textX = shape.getPosition().x + radius - textBounds.width / 2 - textBounds.left + 80;
    float textY = shape.getPosition().y + radius - textBounds.height / 2 - textBounds.top;
    text.setPosition(textX, textY);
}

TimerComponent::~TimerComponent()
{
}

sf::CircleShape TimerComponent::getTimerAsShape()
{
	return shape;
}

sf::Text TimerComponent::getTimeAsText()
{
	text.setString(std::to_string(int(maxTime.asSeconds() - clock.getElapsedTime().asSeconds())));
	return text;
}

sf::Time TimerComponent::getTime()
{
	return maxTime - clock.getElapsedTime();
}

void TimerComponent::restartTimer()
{
	clock.restart();
}