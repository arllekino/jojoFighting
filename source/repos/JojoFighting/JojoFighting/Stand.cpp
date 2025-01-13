#include "Stand.h"

#include "StandType.h"
#include "TextureManager.h"

#include <iostream>

Stand::Stand(StandType type, TextureManager* textureManager, Character* owner)
{
	isVisible = false;
	standType = type;
	texturesMap = textureManager->getStandTextures(type);
	this->owner = owner;
	currentAction = ActionType::onStay;
	body.bodyShape.setPosition(0.f, 0.f);
	
}

Stand::~Stand()
{
}

bool Stand::isStandVisible()
{
	return isVisible;
}

void Stand::onPunch(Character* whosOnPunch)
{
	if (owner->isTimeStoppedMethod())
		return;

	const int punchDeltaHp = getPunchForceByStand();

	auto texturesCount = texturesMap[currentAction].size();

	auto time = clock.getElapsedTime().asSeconds();
	auto frameLivingTime = static_cast<int>(time * punchSpeed);

	int frameIndex = frameLivingTime;
	if (frameIndex >= texturesCount - 1)
	{
		isPunch = false;
		isVisible = false;
		whosOnPunch->makeUnstunned();
	}

	auto position = owner->getPosition();
	auto newSize = texturesMap[currentAction][frameIndex].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position.x, position.y);
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);

	auto bodyShapeProps = body.bodyShape.getGlobalBounds();
	auto punchShapeSize = standType == hermitPurple ? 700 : 50;

	body.punchShape.setSize(sf::Vector2f(punchShapeSize, bodyShapeProps.height));
	body.punchShape.setFillColor(sf::Color::Green);

	auto directionX = body.bodyShape.getScale().x;
	if (directionX > 0)
		body.punchShape.setPosition(bodyShapeProps.left + bodyShapeProps.width - punchShapeSize, bodyShapeProps.top);
	else
		body.punchShape.setPosition(bodyShapeProps.left, bodyShapeProps.top);

	if (body.punchShape.getGlobalBounds().intersects(whosOnPunch->getBody().bodyShape.getGlobalBounds()))
	{
		if (standType == hermitPurple)
		{
			auto whosOnPunchSize = whosOnPunch->getSize();
			auto newPosX = body.bodyShape.getGlobalBounds().left + body.bodyShape.getGlobalBounds().width - whosOnPunchSize.x;
			whosOnPunch->setPositionX(newPosX);
		}

		whosOnPunch->takeDamage(currentAction, body.bodyShape.getScale().x, punchDeltaHp);
		whosOnPunch->makeStunned();
	}
	else
	{
		whosOnPunch->makeUnstunned();

	}
}

void Stand::setVisibility(bool visibility)
{
	isVisible = visibility;
	currentAction = onStay;
	auto texturesCount = texturesMap[currentAction].size();
	if (texturesCount == 0)
		return;

	int frameIndex = static_cast<int>(clock.getElapsedTime().asSeconds() * 10) % texturesCount;
	auto newSize = texturesMap[currentAction][frameIndex].getSize();

	auto position = owner->getPosition();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position);
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);
}

void Stand::checkAction(ActionType type, int direction)
{
	if (isPunch)
	{
		onPunch(opponent);
		return;
	}

	if (type != currentAction)
	{
		currentAction = type;
		clock.restart();
	}

	if (direction != 0)
	{
		body.bodyShape.setScale(direction, 1);
	}
}

void Stand::makePunches()
{
	if (isPunch)
		return;

	isVisible = true;
	isPunch = true;
	clock.restart();
}

void Stand::setOpponent(Character* opponent)
{
	if (this->opponent == nullptr)
		this->opponent = opponent;
}

sf::RectangleShape Stand::getAsShape()
{
	return body.bodyShape;
}

int Stand::getPunchForceByStand()
{
	switch (standType)
	{
	case starPlatinum:
		return 5;
	case theWorld:
		return 5;
	case hermitPurple:
		return 10;
	default:
		break;
	}
}