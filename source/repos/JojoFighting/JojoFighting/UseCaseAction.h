#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

#include "UserType.h"
#include "UserEvent.h"
#include "Character.h"
#include "MenuUserEvent.h"
#include "MenuElement.h"
#include "Game.h"
#include "TextureManager.h"
#include "CharacterCard.h"
#include "ActionType.h"
#include "CharacterType.h"
#include "SupportType.h"
#include "StartGameButton.h"
#include "HealthBarCharacter.h"
#include "UltComponent.h"

class Game;

class UseCaseAction
{
public:
	UseCaseAction(sf::Vector2u windowSize, AudioManager* audioManager);
	~UseCaseAction();

	void processGame(
		Game* game,
		std::unordered_map<UserType, UserEvent> users,
		std::unordered_map<UserType, Character*> characters,
		std::unordered_map<UserType, HealthBarCharacter*> healthBars,
		std::unordered_map<UserType, UltComponent*> ultProgressBars,
		sf::Vector2u windowSize
	);
	void menu(
		Game* game,
		std::unordered_map<UserType, Character*>& characters,
		std::unordered_map<UserType, CharacterType>& chosedCharacters,
		std::unordered_map<UserType, SupportType>& chosedSupports,
		MenuUserEvent menuUserEvent,
		std::vector<CharacterCard*> cards,
		std::vector<CharacterCard*> supportCards,
		StartGameButton* button
	);
	int getCurrentMenuElementPos();

private:
	std::vector<MenuElement> menuElements;
	int menuCurrentElementPos;
	TextureManager* textureManager;
	sf::Vector2u windowSize;
	AudioManager* audioManager;

	StandType getStandTypeByCharacterType(CharacterType type);
	void onAction(std::unordered_map<UserType, Character*> characters, UserType currentUser, UserType otherUser, ActionType action, int direction, sf::Vector2u windowSize, std::unordered_map<UserType, UltComponent*> ultProgressBars);
	int getDirectionByUserEvent(UserEvent userEvent);
	ActionType getActionByUserEvent(UserEvent userEvent);
	void makeHovered(std::vector<CharacterCard*> cards, std::vector<CharacterCard*> supportCards, StartGameButton* button);
	void checkCharacterHp(Character* character, HealthBarCharacter* healthBar);
	void onChooseElement(
		Game* game,
		std::unordered_map<UserType, Character*>& characters,
		std::unordered_map<UserType, CharacterType>& chosedCharacters,
		std::unordered_map<UserType, SupportType>& chosedSupports,
		UserType user,
		MenuElement menuElement,
		MenuUserEvent menuUserEvent
	);
};