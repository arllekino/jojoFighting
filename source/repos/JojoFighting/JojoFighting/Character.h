#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <string>
#include <unordered_map>

#include "CharacterType.h"
#include "StandType.h"
#include "SupportType.h"
#include "Body.h"
#include "Stand.h"
#include "ActionType.h"
#include "TextureManager.h"
#include "AudioManager.h"
#include "UserType.h"
#include "Support.h"
#include "StopTimeEffect.h"
#include "UltComponent.h"
#include "Avatar.h"

class Support;
class Stand;

class Character
{
public:
	Character(TextureManager* textureManager, CharacterType characterType, StandType standType, sf::Vector2u windowSize, UserType user, SupportType supportType);
	~Character();

	Body getBody();
	int getHp();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	CharacterType getCharacterType();
	bool isPunchGoing();
	bool isCharacterHitedNow();
	bool isSupportCalled();
	bool isEffectInProgress();
	bool isTimeStoppedMethod();
	bool isStandVisible();
	bool isDeadMethod();
	int getMaxHp();
	sf::RectangleShape getSupportAsRect();
	std::vector<sf::CircleShape> getSupportAbility();
	sf::CircleShape getEffect();
	sf::RectangleShape getAvatar();
	float getUltReadiness();

	sf::RectangleShape getStandAsShape();

	void checkAction(ActionType type, int direction, Character* opponent);
	void onGoing(float direction, sf::Vector2u fieldSize);
	void onJump(int direction);
	void onPunch(ActionType actionType, Character* whosOnPunch);
	void takeDamage(ActionType action, int punchDirection, int deltaHp);
	void onCrouch(ActionType action);
	void onStay();
	void onSummonStand(ActionType action);
	void onUlt(Character* otherCharacter, UltComponent* ultProgressBar);
	void getUlted(CharacterType byWho);
	void onCallSupport();
	void onHaha(ActionType action);
	void makeStunned();
	void makeUnstunned();
	void setPositionX(float newPosX);

private:
	const float scaleToWindow = 3.3f;
	const int maxHp = 1000;
	const float deltaY = 50;
	const float punchSpeed = 20;
	const float summonSpeed = 20;
	const float moveSpeed = 10;
	const float jumpSpeed = 1000;
	const int gravity = 1500;
	const float recliningDistance = 30.f;
	const sf::Vector2f step = { 10, 0 };
	const sf::Vector2f deadPosition = { -5000, 5000 };
	const sf::Time freezeDuration = sf::seconds(10);
	const sf::Time ultCoolDown = sf::seconds(20);
	const sf::Time atDeathCoolDown = sf::seconds(3);

	sf::Vector2u windowSize;

	int hp;
	sf::Vector2f position{ 500, 600 };
	Body body;
	CharacterType characterType;
	Support* support;
	Stand* stand;
	sf::Clock clock;
	sf::Clock ultClock;
	ActionTexturesMap texturesMap;
	ActionType currentAction;
	std::unordered_map<ActionType, sf::Sound> sounds;
	StopTimeEffect* effect;
	Avatar* avatar;

	AudioManager* audioManager;

	bool isPunch = false;
	bool isHitedNow = false;
	bool isEffectActive = false;
	bool isSoundPlaying = false;
	bool isJump = false;
	bool isAtDeath = false;
	bool isStunned = false;
	bool isWon = false;
	bool isDead = false;

	StandType dependenceFromEnemy;
	bool isTimeStopped = false;
	sf::Clock freezeClock;
	sf::Time startFreezTime;

	sf::Vector2f jumpStartPos;
	sf::Clock jumpClock;
	sf::Clock atDeathClock;

	void stopTime();
	void updateTimeState();
	bool isActionPunch(ActionType action);
	void setActionByAttack(ActionType action);
	bool isActionHited(ActionType action);
	void setHitTexture();
	void checkSound();
	void deadAction();
	void setWinAction();
	sf::Vector2f getAvatarPosByUserType(sf::Vector2u windowSize, UserType userType);
};