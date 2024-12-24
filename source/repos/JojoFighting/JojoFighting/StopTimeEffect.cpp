#include "StopTimeEffect.h"

#include "EffectProgressType.h"

StopTimeEffect::StopTimeEffect()
{
	circle.setFillColor(sf::Color(0, 0, 0, 128));

	circle.setRadius(0.f);
	circle.setPointCount(500);
}

StopTimeEffect::~StopTimeEffect()
{}

void StopTimeEffect::startEffect(sf::Vector2f startPos)
{
	circle.setPosition(startPos);
	effectProgress = inProgressEffect;
}

void StopTimeEffect::checkEffect()
{
    auto prevRadius = circle.getRadius();

    switch (effectProgress)
    {
    case inProgressEffect:
        if (prevRadius < maxRadius)
        {
            auto newRadius = prevRadius + deltaRadius;
            circle.setRadius(newRadius);

            // Устанавливаем якорь в центр круга
            circle.setOrigin(newRadius, newRadius);
        }
        break;

    case endingEffect:
        if (prevRadius > 0)
        {
            auto newRadius = prevRadius - deltaRadius;
            circle.setRadius(newRadius);

            // Устанавливаем якорь в центр круга
            circle.setOrigin(newRadius, newRadius);
        }
        else
        {
            effectProgress = noneProgress;
        }
        break;

    default:
        break;
    }
}

void StopTimeEffect::endEffect()
{
	effectProgress = endingEffect;
}

sf::CircleShape StopTimeEffect::getEffectAsShape()
{
	return circle;
}

EffectProgressType StopTimeEffect::getEffectType()
{
    return effectProgress;
}