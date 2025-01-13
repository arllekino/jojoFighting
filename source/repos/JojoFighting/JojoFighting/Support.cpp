#include "Support.h"

#include <random>
#include <iostream>

#include "SupportType.h"
#include "TextureManager.h"
#include "Character.h"
#include "ActionType.h"

Support::Support(SupportType type, TextureManager* textureManager, sf::Vector2f newSize, sf::Vector2f newPos, int direction)
{
	supportType = type;

	supportTextures = textureManager->getSupportTexture(supportType);
	setSupportTexturesPos(newSize, newPos, direction);
}

Support::~Support()
{
}

void Support::onCallSupport()
{
	if (isSupportVisible)
		return;

	isSupportVisible = true;
	clock.restart();
	switch (supportType)
	{
	case kakyoin:
		callSupportKakyoin();
		break;
	case josuke:
		callSupportJosuke();
		break;
	case kira:
		callSupportKira();
		break;
	default:
		break;
	}
}

void Support::checkSupport(Character* whosOnPunch)
{
	if (clock.getElapsedTime() > callTime) {
		isSupportVisible = false;
		return;
	}

	float speed = 1.f;

	switch (supportType)
	{
	case kakyoin:
		speed = speedEmeraldSplash;
		break;
	case josuke:
		speed = speedJosukeHill;
		break;
	case kira:
		speed = speedKiraBubble;
		break;
	default:
		break;
	}

	checkCollission(whosOnPunch);

	for (auto& item : ability)
	{
		auto prevPos = item.getPosition();
		auto direction = supportRect.getScale().x;
		item.setPosition(prevPos.x + direction * speed, prevPos.y);
	}
}

bool Support::isSupportCalled()
{
	return isSupportVisible;
}

sf::RectangleShape Support::getSupportAsRect()
{
	return supportRect;
}

SupportType Support::getSupportType()
{
	return supportType;
}

std::vector<sf::CircleShape> Support::getAbilitysShapes()
{
	return ability;
}

void Support::callSupportKakyoin()
{
	ability.clear();
	const int emeraldSplashCount = 50;
	const float radius = 10.f;

	std::random_device rd;
	std::mt19937 eng(rd());

	auto direction = supportRect.getScale().x;

	int minX = supportRect.getPosition().x;
	int maxX = supportRect.getPosition().x + supportRect.getSize().x;
	int minY = supportRect.getPosition().y;
	int maxY = supportRect.getPosition().y + supportRect.getSize().y;

	std::uniform_int_distribution<> distrX(minX, maxX);
	std::uniform_int_distribution<> distrY(minY, maxY);

	for (size_t i = 0; i < emeraldSplashCount; i++)
	{
		sf::CircleShape shape(radius);
		shape.setFillColor(sf::Color(5, 218, 115));
		shape.setOutlineColor(sf::Color(0, 181, 38));
		shape.setPosition(sf::Vector2f(distrX(eng), distrY(eng)));
		ability.push_back(shape);
	}
}

void Support::callSupportJosuke()
{
	ability.clear();
	const float radius = 20.f;

	auto direction = supportRect.getScale().x;
	auto supportPos = supportRect.getPosition();
	auto supportSize = supportRect.getSize();

	sf::CircleShape shape(radius);
	shape.setFillColor(sf::Color(248, 19, 11));
	shape.setOutlineColor(sf::Color(0, 0, 0));
	shape.setPosition(supportPos.x + direction * supportSize.y * 3 / 4, supportPos.y + supportSize.y / 2);
	ability.push_back(shape);
}

void Support::callSupportKira()
{
	ability.clear();
	const float radius = 20.f;

	auto direction = supportRect.getScale().x;
	auto supportPos = supportRect.getPosition();
	auto supportSize = supportRect.getSize();

	sf::CircleShape shape(radius);
	shape.setFillColor(sf::Color(250, 174, 209));
	shape.setOutlineColor(sf::Color(255, 23, 145));
	shape.setPosition(supportPos.x + direction * supportSize.y * 3 / 4, supportPos.y + supportSize.y / 2);
	ability.push_back(shape);
}

void Support::setSupportTexturesPos(sf::Vector2f size, sf::Vector2f position, int xDirection)
{
	supportRect.setSize(size);
	supportRect.setPosition(position);
	supportRect.setScale(xDirection, 1);
	if (supportTextures.size() == 0)
	{
		return;
	}
	supportRect.setTexture(&supportTextures[0]);
}

void Support::checkCollission(Character* character)
{
	int damageAmount = 1;

	switch (supportType)
	{
	case kakyoin:
		damageAmount = 1;
		break;
	case josuke:
		damageAmount = -250;
		break;
	case kira:
		damageAmount = 250;
		break;
	default:
		break;
	}

	for (auto it = ability.begin(); it != ability.end();)
	{
		if (it->getGlobalBounds().intersects(character->getBody().bodyShape.getGlobalBounds()))
		{
			if (!character->isPunchGoing()) {
				character->takeDamage(ActionType::onHitedTorsoStraight, supportRect.getScale().x, damageAmount);
				it = ability.erase(it);
			}
		}
		else
		{
			++it;
		}
	}
}
