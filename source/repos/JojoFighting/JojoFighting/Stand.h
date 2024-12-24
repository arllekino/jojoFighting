#pragma once

#include <SFML/Graphics.hpp>

#include "StandType.h"
#include "Body.h"
#include "ActionTexturesMap.h"
#include "ActionType.h"
#include "TextureManager.h"
#include "Character.h"

class Character;

class Stand
{
public:
	Stand(StandType type, TextureManager* textureManager, Character* owner);
	~Stand();

	bool isStandVisible();
	void onPunch(Character* whosOnPunch);
	void setVisibility(bool visibility);
	void checkAction(ActionType type, int direction);
	void makePunches();
	void setOpponent(Character* opponent);

private:
	const float scaleToWindow = 3.3f;
	const float punchSpeed = 20;

	bool isPunch = false;
	Character* opponent;
	Character* owner;
	StandType standType;
	Body body;
	bool isVisible;
	sf::Clock clock;
	ActionTexturesMap texturesMap;
	ActionType currentAction;
};