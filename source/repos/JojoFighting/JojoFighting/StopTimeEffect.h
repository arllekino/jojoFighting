#pragma once

#include <SFML/Graphics.hpp>

#include "EffectProgressType.h"

class StopTimeEffect
{
public:
	StopTimeEffect();
	~StopTimeEffect();

	EffectProgressType getEffectType();

	void startEffect(sf::Vector2f startPos);
	void checkEffect();
	void endEffect();

	sf::CircleShape getEffectAsShape();

private:
	const float maxRadius = 2000.f;
	float deltaRadius = 50.f;
	sf::CircleShape circle;

	EffectProgressType effectProgress = noneProgress;
};