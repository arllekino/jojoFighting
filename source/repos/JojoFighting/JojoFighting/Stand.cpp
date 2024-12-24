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
	isPunch = true;
	if (owner->isTimeStoppedMethod())
		return;

	const int punchDeltaHp = 5;

	auto texturesCount = texturesMap[currentAction].size();

	auto time = clock.getElapsedTime().asSeconds();
	auto frameLivingTime = static_cast<int>(time * punchSpeed);

	int frameIndex;
	if (frameLivingTime < texturesCount)
		frameIndex = frameLivingTime;

	if (frameIndex == texturesCount - 1)
		isPunch = false;

	auto position = owner->getPosition();
	auto newSize = texturesMap[currentAction][frameIndex].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position.x, position.y - newSize.y * scaleToWindow);
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);

	auto bodyShapeProps = body.bodyShape.getGlobalBounds();
	body.punchShape.setSize(sf::Vector2f(50, bodyShapeProps.height));
	body.punchShape.setFillColor(sf::Color::Green);

	auto directionX = body.bodyShape.getScale().x;
	if (directionX > 0)
		body.punchShape.setPosition(bodyShapeProps.left + bodyShapeProps.width - 50, bodyShapeProps.top);
	else
		body.punchShape.setPosition(bodyShapeProps.left, bodyShapeProps.top);

	if (body.punchShape.getGlobalBounds().intersects(whosOnPunch->getBody().bodyShape.getGlobalBounds()))
		whosOnPunch->takeDamage(currentAction, body.bodyShape.getScale().x, punchDeltaHp);
}

void Stand::setVisibility(bool visibility)
{
	isVisible = visibility;
	currentAction = onStay;
	auto texturesCount = texturesMap[currentAction].size();
	if (texturesCount == 0)
		return;

	int frameIndex = static_cast<int>(clock.getElapsedTime().asSeconds() * 10) % texturesCount;
	auto newSize = texturesMap[currentAction][0].getSize();

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
	isVisible = true;
	isPunch = true;
}

void Stand::setOpponent(Character* opponent)
{
	if (this->opponent == nullptr)
		this->opponent = opponent;
}