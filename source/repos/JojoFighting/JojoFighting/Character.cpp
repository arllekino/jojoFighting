#include "Character.h"

#include <format>
#include <random>

#include <iostream>

#include "StandType.h"
#include "CharacterType.h"
#include "Body.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "Stand.h"
#include "UserType.h"
#include "StopTimeEffect.h"

Character::Character(TextureManager* textureManager, CharacterType characterType, StandType standType, sf::Vector2u windowSize, UserType user, SupportType supportType)
{
	const float windowPadding = 200.f;
	const float yPos = 600.f;
	const sf::Vector2f startSize = sf::Vector2f(230, 450);

	this->windowSize = windowSize;

	stand = new Stand(standType, textureManager, this);
	hp = maxHp;
	this->characterType = characterType;

	texturesMap = textureManager->getCharacterTextures(characterType);

	currentAction = ActionType::onStay;
	sf::Vector2f newPosition;
	int direction = 1;
	if (user == firstUser)
	{
		newPosition = sf::Vector2f(windowPadding, yPos);
		direction = 1;
	}
	if (user == secondUser)
	{
		newPosition = sf::Vector2f(windowSize.x - windowPadding, yPos);
		direction = -1;
	}

	body.bodyShape.setPosition(newPosition);
	body.bodyShape.setScale(direction, 1);
	body.bodyShape.setSize(startSize);
	body.bodyShape.setOrigin(body.bodyShape.getGlobalBounds().width / 2, -body.bodyShape.getGlobalBounds().height / 16);
	body.bodyShape.setOutlineColor(sf::Color::Green);
	body.bodyShape.setOutlineThickness(2);

	position = sf::Vector2f(newPosition.x, 1040);

	support = new Support(supportType, textureManager, sf::Vector2f(startSize.x - 30, startSize.y - 100), sf::Vector2f(newPosition.x, newPosition.y + 100), direction);
	audioManager = new AudioManager();
	effect = new StopTimeEffect();
}

Character::~Character()
{
	delete effect;
	delete support;
	delete stand;
}

Body Character::getBody()
{
	return body;
}

int Character::getHp()
{
	return hp;
}

sf::Vector2f Character::getPosition()
{
	return position;
}

CharacterType Character::getCharacterType()
{
	return characterType;
}

bool Character::isPunchGoing()
{
	return isPunch;
}

bool Character::isCharacterHitedNow()
{
	return isHitedNow;
}

bool Character::isSupportCalled()
{
	return support->isSupportCalled();
}

bool Character::isEffectInProgress()
{
	return isEffectActive;
}

bool Character::isTimeStoppedMethod()
{
	return isTimeStopped;
}

int Character::getMaxHp()
{
	return maxHp;
}

sf::RectangleShape Character::getSupportAsRect()
{
	return support->getSupportAsRect();
}

std::vector<sf::CircleShape> Character::getSupportAbility()
{
	return support->getAbilitysShapes();
}

sf::CircleShape Character::getEffect()
{
	return effect->getEffectAsShape();
}

float Character::getUltReadiness()
{
	auto progress = ultClock.getElapsedTime().asSeconds() / ultCoolDown.asSeconds();

	return progress < 1 ? progress : 1;
}

void Character::checkAction(ActionType type, int direction, Character* opponent)
{
	stand->setOpponent(opponent);
	if (isAtDeath)
	{
		currentAction = atDeath;
		deadAction();
		return;
	}

	if (isHitedNow)
	{
		setHitTexture();
		if (!isTimeStopped)
			return;
	}

	effect->checkEffect();
	if (isTimeStopped)
	{
		updateTimeState();
		return;
	}

	support->checkSupport(support->getSupportType() == josuke ? this : opponent);

	if (isEffectActive)
		updateTimeState();

	if (type == ActionType::onJump || isJump)
		this->onJump(direction);

	if (type == ActionType::onStay && !isJump)
		this->onStay();

	checkSound();
	if (type != currentAction && (type == ActionType::onJump || !isJump))
	{
		isPunch = isActionPunch(type);

		currentAction = type;
		clock.restart();
	}

	if (direction != 0)
	{
		body.bodyShape.setScale(direction, 1);
	}

	stand->checkAction(type, direction);
	if (currentAction == onOraOra)
		stand->makePunches();
	if (characterType == dio && hp < maxHp)
		hp++;
}

void Character::onStay()
{
	if (isTimeStopped || isJump)
		return;

	auto texturesCount = texturesMap[currentAction].size();

	auto time = isTimeStopped ? startFreezTime.asSeconds() : clock.getElapsedTime().asSeconds();

	int frameIndex = static_cast<int>(int(time * moveSpeed) % texturesCount);
	auto newSize = texturesMap[currentAction][frameIndex].getSize();

	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position.x, position.y - newSize.y * scaleToWindow);
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);
}

void Character::onGoing(float direction, sf::Vector2u fieldSize)
{
	if (isTimeStopped || isJump)
		return;

	const float gap = 60;
	auto prevPosition = body.bodyShape.getPosition();
	auto bounds = body.bodyShape.getGlobalBounds();

	if (prevPosition.x - bounds.width / 2 + direction * step.x > gap && prevPosition.x + bounds.width / 2 + direction * step.x < fieldSize.x - gap)
	{
		position.x = prevPosition.x + direction * step.x;
		body.bodyShape.setPosition(prevPosition + direction * step);
	}
	currentAction = ActionType::onGoing;
	auto texturesCount = texturesMap[currentAction].size();

	auto time = clock.getElapsedTime().asSeconds();
	int frameIndex = static_cast<int>(int(time * moveSpeed) % texturesCount);

	auto newSize = texturesMap[currentAction][frameIndex].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);

	audioManager->playSound(characterType, currentAction);
}

void Character::onJump(int direction)
{
	if (isTimeStopped)
		return;
	if (!isJump)
	{
		isJump = true;
		jumpClock.restart();
	}

	auto jumpSeconds = jumpClock.getElapsedTime().asSeconds();
	auto deltaY = -jumpSpeed * jumpSeconds + gravity * jumpSeconds * jumpSeconds / 2;

	auto texturesCount = texturesMap[currentAction].size();

	auto time = isTimeStopped ? freezeClock.getElapsedTime().asSeconds() : jumpClock.getElapsedTime().asSeconds();
	auto frameLivingTime = static_cast<int>(time * 10);

	int frameIndex;
	if (frameLivingTime < texturesCount)
	{
		frameIndex = frameLivingTime;
	}
	else
	{
		isJump = false;
		frameIndex = texturesCount - 1;
	}
	auto newSize = texturesMap[currentAction][frameIndex].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	float stepX = step.x * direction;
	if (deltaY < 0)
	{
		body.bodyShape.setPosition(position.x + stepX, position.y - newSize.y * scaleToWindow + deltaY);
		position.x += stepX;
	}
	else
		body.bodyShape.setPosition(position.x, position.y - newSize.y * scaleToWindow);
	
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);
}

void Character::onPunch(ActionType actionType, Character* whosOnPunch)
{
	if (isTimeStopped || isJump)
		return;

	const int punchDeltaHp = 5;

	auto texturesCount = texturesMap[currentAction].size();

	auto time = isTimeStopped ? freezeClock.getElapsedTime().asSeconds() : clock.getElapsedTime().asSeconds();
	auto frameLivingTime = static_cast<int>(time * punchSpeed);

	int frameIndex;
	if (frameLivingTime < texturesCount)
		frameIndex = frameLivingTime;
	else
	{
		isPunch = false;
		return;
	}

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
		whosOnPunch->takeDamage(actionType, body.bodyShape.getScale().x, punchDeltaHp);
}

void Character::takeDamage(ActionType action, int punchDirection, int deltaHp)
{
	if (!isTimeStopped)
		audioManager->playSound(characterType, onTakeHit);

	if (isActionPunch(action))
	{
		clock.restart();
		setActionByAttack(action);
	}

	body.bodyShape.setOutlineColor(sf::Color::Red);
	auto prevPosition = body.bodyShape.getPosition();
	auto bodySize = body.bodyShape.getSize();

	if (prevPosition.x - bodySize.x + punchDirection * recliningDistance > 0 && prevPosition.x + bodySize.x + punchDirection * recliningDistance < windowSize.x)
	{
		auto newPosition = sf::Vector2f(prevPosition.x + punchDirection * recliningDistance, prevPosition.y);
		position = sf::Vector2f(newPosition.x, newPosition.y + body.bodyShape.getSize().y);
	}

	if (hp >= 0)
		hp -= deltaHp;

	if (hp < 0)
	{
		hp = 0;
		isAtDeath = true;
		//body.bodyShape.setPosition(deadPosition);
	}

	if (hp > maxHp)
		hp = maxHp;
}

void Character::onCrouch(ActionType action)
{
	if (isTimeStopped || isJump)
		return;

	auto texturesCount = texturesMap[currentAction].size();

	auto time = isTimeStopped ? freezeClock.getElapsedTime().asSeconds() : clock.getElapsedTime().asSeconds();
	auto frameLivingTime = static_cast<int>(time * 10);

	int frameIndex = frameLivingTime < texturesCount ? frameLivingTime : texturesCount - 1;
	auto newSize = texturesMap[currentAction][frameIndex].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position.x, position.y - newSize.y * scaleToWindow);
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);
}

void Character::onSummonStand(ActionType action)
{
	if (isTimeStopped || isJump)
		return;

	if (stand->isStandVisible())
		return;

	auto texturesCount = texturesMap[currentAction].size();

	auto time = isTimeStopped ? freezeClock.getElapsedTime().asSeconds() : clock.getElapsedTime().asSeconds();
	auto frameLivingTime = static_cast<int>(time * summonSpeed);

	int frameIndex = frameLivingTime < texturesCount ? frameLivingTime : texturesCount - 1;
	auto newSize = texturesMap[currentAction][frameIndex].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position.x, position.y - newSize.y * scaleToWindow);
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);

	if (frameIndex == texturesCount - 1)
	{
		stand->setVisibility(true);
	}
}

void Character::onUlt(ActionType action, Character* otherCharacter, UltComponent* ultProgressBar)
{
	if (isTimeStopped || isJump)
		return;

	if (getUltReadiness() < 1)
		return;

	audioManager->playSound(characterType, action);
	auto texturesCount = texturesMap[currentAction].size();

	auto time = isTimeStopped ? freezeClock.getElapsedTime().asSeconds() : clock.getElapsedTime().asSeconds();
	auto frameLivingTime = static_cast<int>(time * summonSpeed);

	int frameIndex = frameLivingTime < texturesCount ? frameLivingTime : texturesCount - 1;
	auto newSize = texturesMap[currentAction][frameIndex].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position.x, position.y - newSize.y * scaleToWindow);
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);

	if (frameIndex == texturesCount - 1)
	{
		freezeClock.restart();
		audioManager->stopMusic();
		effect->startEffect(body.bodyShape.getPosition());
		isEffectActive = true;
		otherCharacter->getUlted(characterType);
		ultProgressBar->reset();
		ultClock.restart();
	}
}

void Character::getUlted(CharacterType byWho)
{
	switch (byWho) {
	case jotaro:
		stopTime();
		break;
	case dio:
		stopTime();
		break;
	default:
		break;
	}
}

void Character::onCallSupport()
{
	if (isTimeStopped)
		return;
	audioManager->playSound(characterType, ActionType::onCallSupport);
	support->onCallSupport();
}

void Character::stopTime()
{
	isTimeStopped = true;
	startFreezTime = freezeClock.getElapsedTime();
	freezeClock.restart();
}

void Character::updateTimeState()
{
	if (isEffectActive && freezeClock.getElapsedTime().asSeconds() > freezeDuration.asSeconds())
	{
		effect->endEffect();
		if (effect->getEffectType() == noneProgress)
		{
			audioManager->continueMusic();
			isEffectActive = false;
		}
	}

	if (isTimeStopped && freezeClock.getElapsedTime() > freezeDuration)
	{
		isTimeStopped = false;
	}
}

bool Character::isActionPunch(ActionType action)
{
	switch (action)
	{
	case onStandAttack:
	case onCrouchAttackForward:
	case onCrouchPowerfulAttackForward:
	case onArmMediumAttack:
	case onLegMediumAttack:
	case onLegMediumAttackMidAir:
	case onStandCrouchingAttack:
	case onStandAttackUp:
	case onStandAttackDown:
	case onStandAttackCrouchingDown:
	case onStandAttackCrouchingUp:
	case onOraOra:
		return true;

	default:
		return false;
	}
}

void Character::setActionByAttack(ActionType action)
{
	switch (action)
	{
	case onStandAttack:
		break;
	case onCrouchAttackForward:
		isHitedNow = true;
		currentAction = onHitedLegStraight;
		break;
	case onCrouchPowerfulAttackForward:
		break;
	case onArmMediumAttack:
		isHitedNow = true;
		currentAction = onHitedHeadStraight;
		break;
	case onLegMediumAttack:
		break;
	case onLegMediumAttackMidAir:
		break;
	case onStandCrouchingAttack:
		break;
	case onStandAttackUp:
		isHitedNow = true;
		currentAction = onHitedTorsoDownUp;
		break;
	case onStandAttackDown:
		break;
	case onStandAttackCrouchingDown:
		break;
	case onStandAttackCrouchingUp:
		break;
	case onOraOra:
		break;

	default:
		return;
	}

	auto newSize = texturesMap[currentAction][0].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position.x, position.y - newSize.y * scaleToWindow);
	body.bodyShape.setTexture(&texturesMap[currentAction][0], true);
}

bool Character::isActionHited(ActionType action)
{
	switch (action)
	{
	case onHitedHeadStraight:
	case onHitedHeadDownUp:
	case onHitedHeadUpDown:
	case onHitedTorsoStraight:
	case onHitedTorsoDownUp:
	case onHitedLegStraight:
	case onHitedLegWithFall:
	case onHitedTorsoWithFall:
	case onHitedInSit:
	case onHitedInJump:
		return true;
	default:
		return false;
	}
}

void Character::setHitTexture()
{
	auto texturesCount = texturesMap[currentAction].size();
	auto time = isTimeStopped ? freezeClock.getElapsedTime().asSeconds() : clock.getElapsedTime().asSeconds();
	auto frameLivingTime = static_cast<int>(time * summonSpeed);

	int frameIndex = frameLivingTime < texturesCount ? frameLivingTime : texturesCount - 1;
	auto newSize = texturesMap[currentAction][frameIndex].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position.x, position.y - newSize.y * scaleToWindow);
	if (isTimeStopped)
		frameIndex = 0;
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);

	if (frameIndex == texturesCount - 1)
	{
		isHitedNow = false;
		currentAction = ActionType::onStay;
	}
}

void Character::checkSound()
{
	if (!isPunch)
		return;

	switch (currentAction)
	{
		//case onStandingFromCrouch:
			//break;
	case ActionType::onCrouch://
		audioManager->playSound(characterType, currentAction);
		break;
	case onStandAttack:
		break;
	case onCrouchAttackForward://
		audioManager->playSound(characterType, currentAction);
		break;
	case onCrouchPowerfulAttackForward://
		audioManager->playSound(characterType, currentAction);
		break;
	case onArmMediumAttack://
		audioManager->playSound(characterType, currentAction);
		break;
	case onLegMediumAttack:
		break;
	case onLegMediumAttackMidAir:
		break;
	case onStandCrouchingAttack:
		break;
	case onStandAttackUp://
		audioManager->playSound(characterType, currentAction);
		break;
	case onStandAttackDown://
		audioManager->playSound(characterType, currentAction);
		break;
	case onStandAttackCrouchingDown:
		break;
	case onStandAttackCrouchingUp:
		break;
	case onOraOra:
		break;
	case onHitedHeadStraight:
		break;
	case onHitedHeadDownUp:
		break;
	case onHitedHeadUpDown:
		break;
	case onHitedTorsoStraight:
		break;
	case onHitedTorsoDownUp:
		break;
	case onHitedLegStraight:
		break;
	case onHitedLegWithFall:
		break;
	case onHitedTorsoWithFall:
		break;
	case onHitedInSit:
		break;
	case ActionType::onCallSupport:
		audioManager->playSound(characterType, currentAction);
		break;
	default:
		break;
	}
}

void Character::onHaha(ActionType action)
{
	if (isTimeStopped)
		return;

	auto texturesCount = texturesMap[currentAction].size();
	auto time = isTimeStopped ? startFreezTime.asSeconds() : clock.getElapsedTime().asSeconds();
	auto frameLivingTime = static_cast<int>(time * moveSpeed);

	int frameIndex = frameLivingTime < texturesCount ? frameLivingTime : texturesCount - 1;
	if (frameIndex == 0)
		audioManager->playSound(characterType, currentAction);

	auto newSize = texturesMap[currentAction][frameIndex].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position.x, position.y - newSize.y * scaleToWindow);
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);
}

void Character::deadAction()
{
	//if (isTimeStopped)
		//return;

	auto texturesCount = texturesMap[atDeath].size();
	auto time = clock.getElapsedTime().asSeconds();
	auto frameLivingTime = static_cast<int>(time * moveSpeed);

	int frameIndex = frameLivingTime < texturesCount ? frameLivingTime : texturesCount - 1;

	auto newSize = texturesMap[currentAction][frameIndex].getSize();
	body.bodyShape.setSize(sf::Vector2f(newSize.x, newSize.y) * scaleToWindow);
	body.bodyShape.setPosition(position.x, position.y - newSize.y * scaleToWindow);
	body.bodyShape.setTexture(&texturesMap[currentAction][frameIndex], true);
}