#include "UseCaseAction.h"

#include <vector>
#include <unordered_map>
#include <iostream>

#include "Game.h"
#include "CharacterCard.h"
#include "MenuUserEvent.h"
#include "Character.h"
#include "UserType.h"
#include "UserEvent.h"
#include "TextureManager.h"
#include "MenuElement.h"

UseCaseAction::UseCaseAction(sf::Vector2u windowSize, AudioManager* audioManager)
{
	this->windowSize = windowSize;

	textureManager = new TextureManager();
	this->audioManager = audioManager;

	menuElements.push_back(MenuElement::elementJotaro);
	menuElements.push_back(MenuElement::elementDio);
	menuElements.push_back(MenuElement::elementJosuke);
	menuElements.push_back(MenuElement::elementKakyoin);
	menuElements.push_back(MenuElement::elementKira);

	menuElements.push_back(MenuElement::startGame);

	menuCurrentElementPos = 0;
}

UseCaseAction::~UseCaseAction()
{
	delete textureManager;
}

void UseCaseAction::menu(
	Game* game,
	std::unordered_map<UserType, Character*>& characters,
	std::unordered_map<UserType, CharacterType>& chosedCharacters,
	std::unordered_map<UserType, SupportType>& chosedSupports,
	MenuUserEvent menuUserEvent,
	std::vector<CharacterCard*> cards,
	std::vector<CharacterCard*> supportCards,
	StartGameButton* startGameButton
)
{
	switch (menuUserEvent)
	{
	case left:
		if (menuCurrentElementPos > 0)
		{
			audioManager->playMenuSound(menuUserEvent);
			menuCurrentElementPos--;
			makeHovered(cards, supportCards, startGameButton);
		}
		break;
	case right:
		if (menuElements.size() - 1 > menuCurrentElementPos)
		{
			audioManager->playMenuSound(menuUserEvent);
			menuCurrentElementPos++;
			makeHovered(cards, supportCards, startGameButton);
		}
		break;
	case onToggleFirstUser:
		onChooseElement(game, characters, chosedCharacters, chosedSupports, UserType::firstUser, menuElements[menuCurrentElementPos], menuUserEvent);
		if (menuElements[menuCurrentElementPos] == elementJotaro)
			if (chosedCharacters[firstUser] != noneCharacter)
			{
				cards[0]->makeCardSelected(UserType::firstUser);
				audioManager->playMenuSound(menuUserEvent);
			}
			else
				cards[0]->makeCardUnselected();
		
		if (menuElements[menuCurrentElementPos] == elementDio)
			if (chosedCharacters[firstUser] != noneCharacter)
			{
				cards[1]->makeCardSelected(UserType::firstUser);
				audioManager->playMenuSound(menuUserEvent);
			}
			else
				cards[1]->makeCardUnselected();

		if (menuElements[menuCurrentElementPos] == elementJosuke)
			if (chosedSupports[firstUser] != noneSupport)
			{
				supportCards[0]->makeCardSelected(UserType::firstUser);
				audioManager->playMenuSound(menuUserEvent);
			}
			else
				supportCards[0]->makeCardUnselected();

		if (menuElements[menuCurrentElementPos] == elementKakyoin)
			if (chosedSupports[firstUser] != noneSupport)
			{
				supportCards[1]->makeCardSelected(UserType::firstUser);
				audioManager->playMenuSound(menuUserEvent);
			}
			else
				supportCards[1]->makeCardUnselected();

		if (menuElements[menuCurrentElementPos] == elementKira)
			if (chosedSupports[firstUser] != noneSupport)
			{
				supportCards[2]->makeCardSelected(UserType::firstUser);
				audioManager->playMenuSound(menuUserEvent);
			}
			else
				supportCards[2]->makeCardUnselected();
		break;
	case onToggleSecondUser:
		onChooseElement(game, characters, chosedCharacters, chosedSupports, UserType::secondUser, menuElements[menuCurrentElementPos], menuUserEvent);
		if (menuElements[menuCurrentElementPos] == elementJotaro)
			if (chosedCharacters[secondUser] != noneCharacter)
			{
				cards[0]->makeCardSelected(UserType::secondUser);
				audioManager->playMenuSound(menuUserEvent);
			}
			else
				cards[0]->makeCardUnselected();

		if (menuElements[menuCurrentElementPos] == elementDio)
			if (chosedCharacters[secondUser] != noneCharacter)
			{
				cards[1]->makeCardSelected(UserType::secondUser);
				audioManager->playMenuSound(menuUserEvent);
			}
			else
				cards[1]->makeCardUnselected();

		if (menuElements[menuCurrentElementPos] == elementJosuke)
			if (chosedSupports[secondUser] != noneSupport)
			{
				supportCards[0]->makeCardSelected(UserType::secondUser);
				audioManager->playMenuSound(menuUserEvent);
			}
			else
				supportCards[0]->makeCardUnselected();

		if (menuElements[menuCurrentElementPos] == elementKakyoin)
			if (chosedSupports[secondUser] != noneSupport)
			{
				supportCards[1]->makeCardSelected(UserType::secondUser);
				audioManager->playMenuSound(menuUserEvent);
			}
			else
				supportCards[2]->makeCardUnselected();

		if (menuElements[menuCurrentElementPos] == elementKira)
			if (chosedSupports[secondUser] != noneSupport)
			{
				supportCards[2]->makeCardSelected(UserType::secondUser);
				audioManager->playMenuSound(menuUserEvent);
			}
			else
				supportCards[2]->makeCardUnselected();
		break;
	case onEnter:
	{
		bool characterReadiness = true;
		for (auto& chosedCharacter : chosedCharacters)
		{
			if (!characterReadiness)
				break;

			characterReadiness = chosedCharacter.second != noneCharacter;
		}

		bool supportReadiness = true;
		for (auto& chosedSupport : chosedSupports)
		{
			if (!supportReadiness)
				break;

			supportReadiness = chosedSupport.second != noneSupport;
		}

		if (characterReadiness && supportReadiness)
		{
			characters[firstUser] = new Character(
				textureManager,
				chosedCharacters[firstUser],
				getStandTypeByCharacterType(chosedCharacters[firstUser]),
				windowSize,
				firstUser,
				chosedSupports[firstUser]
			);

			characters[secondUser] = new Character(
				textureManager,
				chosedCharacters[secondUser],
				getStandTypeByCharacterType(chosedCharacters[secondUser]),
				windowSize,
				secondUser,
				chosedSupports[secondUser]
			);

			game->setGameState(GameState::game);
			audioManager->playMenuSound(menuUserEvent);
		}
		break;
	}
	case noAction:
		break;
	default:
		break;
	}
}

void UseCaseAction::processGame(
	Game* game,
	std::unordered_map<UserType, UserEvent> users,
	std::unordered_map<UserType, Character*> characters,
	std::unordered_map<UserType, HealthBarCharacter*> healthBars,
	std::unordered_map<UserType, UltComponent*> ultProgressBars,
	sf::Vector2u windowSize
)
{
	if (game->getTime().asSeconds() < 0)
	{
		game->setGameState(GameState::menu);
		return;
	}

	auto firstUserAction = getActionByUserEvent(users[firstUser]);
	int firstUserDirection = getDirectionByUserEvent(users[firstUser]);

	checkCharacterHp(characters[firstUser], healthBars[firstUser]);
	onAction(characters, firstUser, secondUser, firstUserAction, firstUserDirection, windowSize, ultProgressBars);
	ultProgressBars[firstUser]->check(characters[firstUser]->getUltReadiness());


	auto secondUserAction = getActionByUserEvent(users[secondUser]);
	int secondUserDirection = getDirectionByUserEvent(users[secondUser]);

	checkCharacterHp(characters[secondUser], healthBars[secondUser]);
	onAction(characters, secondUser, firstUser, secondUserAction, secondUserDirection, windowSize, ultProgressBars);
	ultProgressBars[secondUser]->check(characters[secondUser]->getUltReadiness());
}

int UseCaseAction::getCurrentMenuElementPos()
{
	return menuCurrentElementPos;
}

ActionType UseCaseAction::getActionByUserEvent(UserEvent userEvent)
{
	ActionType userAction = onStay;

	switch (userEvent)
	{
	case none:
		userAction = ActionType::onStay;
		break;
	case onLeft:
		userAction = ActionType::onGoing;
		break;
	case onUp:
	case onUpRight: 
	case onUpLeft:
		userAction = ActionType::onJump;
		break;
	case onRight:
		userAction = ActionType::onGoing;
		break;
	case onCrouching:
		userAction = ActionType::onCrouch;
		break;
	case onMediumArmAttack:
		userAction = ActionType::onArmMediumAttack;
		break;
	case onCharacterStandAttackUp:
		userAction = ActionType::onStandAttackUp;
		break;
	case onSummonStand:
		userAction = ActionType::onSummon;
		break;
	case ult:
		userAction = ActionType::onUlt;
		break;
	case onCrouchPunchForward:
		userAction = ActionType::onCrouchAttackForward;
		break;
	case onCrouchPunchPowerful:
		userAction = ActionType::onCrouchPowerfulAttackForward;
		break;
	case onCharacterStandAttackDown:
		userAction = ActionType::onStandAttackDown;
		break;
	case onSupportCall:
		userAction = ActionType::onCallSupport;
		break;
	case ridicule:
		userAction = ActionType::onHaha;
		break;
	default:
		userAction = ActionType::onStay;
		break;
	}

	return userAction;
}

int UseCaseAction::getDirectionByUserEvent(UserEvent userEvent)
{
	int direction = 0;
	switch (userEvent)
	{
	case onLeft:
	case onUpLeft:
		direction = -1;
		break;
	case onRight:
	case onUpRight:
		direction = 1;
		break;
	default:
		break;
	}

	return direction;
}

void UseCaseAction::onAction(
	std::unordered_map<UserType, Character*> characters,
	UserType currentUser,
	UserType otherUser,
	ActionType action,
	int direction,
	sf::Vector2u windowSize,
	std::unordered_map<UserType, UltComponent*> ultProgressBars
)
{
	characters[currentUser]->checkAction(action, direction, characters[otherUser]);
	if (characters[currentUser]->isCharacterHitedNow())
		return;

	if (action == ActionType::onGoing)
		characters[currentUser]->onGoing(float(direction), windowSize);
	if (action == ActionType::onArmMediumAttack
		|| action == ActionType::onStandAttackUp
		|| action == ActionType::onCrouchAttackForward
		|| action == ActionType::onCrouchPowerfulAttackForward
		|| action == ActionType::onStandAttackDown
		) {
		characters[currentUser]->onPunch(action, characters[otherUser]);
	}
	if (action == ActionType::onCrouch)
		characters[currentUser]->onCrouch(action);
	if (action == ActionType::onSummon)
		characters[currentUser]->onSummonStand(action);
	if (action == ActionType::onUlt)
		characters[currentUser]->onUlt(action, characters[otherUser], ultProgressBars[currentUser]);
	if (action == ActionType::onCallSupport)
		characters[currentUser]->onCallSupport();
	if (action == ActionType::onHaha)
		characters[currentUser]->onHaha(action);
}

void UseCaseAction::onChooseElement(
	Game* game,
	std::unordered_map<UserType, Character*>& characters,
	std::unordered_map<UserType, CharacterType>& chosedCharacters,
	std::unordered_map<UserType, SupportType>& chosedSupports,
	UserType user,
	MenuElement menuElement,
	MenuUserEvent menuUserEvent
)
{
	switch (menuElement)
	{
	case closeGame:
		break;
	case elementJotaro:
		if (chosedCharacters[user] == noneCharacter)
			chosedCharacters[user] = jotaro;
		else
			chosedCharacters[user] = noneCharacter;
		break;
	case elementDio:
		if (chosedCharacters[user] == noneCharacter)
			chosedCharacters[user] = dio;
		else
			chosedCharacters[user] = noneCharacter;
		break;
	case elementJosuke:
		if (chosedSupports[user] == noneSupport)
			chosedSupports[user] = josuke;
		else
			chosedSupports[user] = noneSupport;
		break;
	case elementKakyoin:
		if (chosedSupports[user] == noneSupport)
			chosedSupports[user] = kakyoin;
		else
			chosedSupports[user] = noneSupport;
		break;
	case elementKira:
		if (chosedSupports[user] == noneSupport)
			chosedSupports[user] = kira;
		else
			chosedSupports[user] = noneSupport;
		break;
	case startGame:
	{
		bool characterReadiness = true;
		for (auto& chosedCharacter : chosedCharacters)
		{
			if (!characterReadiness)
				break;

			characterReadiness = chosedCharacter.second != noneCharacter;
		}

		bool supportReadiness = true;
		for (auto& chosedSupport : chosedSupports)
		{
			if (!supportReadiness)
				break;

			supportReadiness = chosedSupport.second != noneSupport;
		}

		if (characterReadiness && supportReadiness)
		{
			characters[firstUser] = new Character(
				textureManager,
				chosedCharacters[firstUser],
				getStandTypeByCharacterType(chosedCharacters[firstUser]),
				windowSize,
				firstUser,
				chosedSupports[firstUser]
			);

			characters[secondUser] = new Character(
				textureManager,
				chosedCharacters[secondUser],
				getStandTypeByCharacterType(chosedCharacters[secondUser]),
				windowSize,
				secondUser,
				chosedSupports[secondUser]
			);

			game->setGameState(GameState::game);
		}

		break;
	}
	default:
		break;
	}
}

void UseCaseAction::makeHovered(std::vector<CharacterCard*> cards, std::vector<CharacterCard*> supportCards, StartGameButton* button)
{
	auto unhoverAllCards = [&]() {
		for (auto& card : cards) {
			card->makeCardUnhovered();
		}
		for (auto& supportCard : supportCards) {
			supportCard->makeCardUnhovered();
		}
	};

	auto unhoverButton = [&]() {
		button->makeButtonUnhovered();
	};

	unhoverAllCards();
	unhoverButton();

	switch (menuElements[menuCurrentElementPos]) {
	case elementJotaro:
		cards[0]->makeCardHovered();
		break;
	case elementDio:
		cards[1]->makeCardHovered();
		break;
	case elementJosuke:
		supportCards[0]->makeCardHovered();
		break;
	case elementKakyoin:
		supportCards[1]->makeCardHovered();
		break;
	case elementKira:
		supportCards[2]->makeCardHovered();
		break;
	case startGame:
		button->makeButtonHovered();
		break;
	default:
		break;
	}
}

void UseCaseAction::checkCharacterHp(Character* character, HealthBarCharacter* healthBar)
{
	healthBar->setProgress(character->getHp(), character->getMaxHp());
}

StandType UseCaseAction::getStandTypeByCharacterType(CharacterType type)
{
	switch (type)
	{
	case jotaro:
		return starPlatinum;
	case dio:
		return theWorld;
	default:
		return noneStand;
	}
}