#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <string>

#include "UseCaseAction.h"
#include "GameState.h"
#include "PollEvent.h"
#include "Drawable.h"
#include "TextureManager.h"
#include "Character.h"
#include "CharacterCard.h"
#include "MenuUserEvent.h"
#include "UserEvent.h"
#include "UserType.h"
#include "StartGameButton.h"
#include "HealthBarCharacter.h"
#include "AudioManager.h"
#include "TimerComponent.h"
#include "UltComponent.h"

class UseCaseAction;

class Game
{
public:
	Game(sf::Vector2u windowSize);
	~Game();

	GameState getGameState();
	void setGameState(GameState state);

	void menu(sf::RenderWindow& window);
	void main(sf::RenderWindow& window);

	sf::Time getTime();

private:
	const float windowPadding = 50.f;
	const std::string menuBackgroundPath = "assets/game/menuBackground.jpg";
	const std::string gameBackgroundPath = "assets/game/CairoStreet.jpg";

	PollEvent* pollEvent;
	UseCaseAction* useCaseAction;
	Drawable* drawable;

	GameState gameState = GameState::menu;
	MenuUserEvent menuUserEvent = MenuUserEvent::noAction;
	std::vector<CharacterCard*> cards;
	std::vector<CharacterCard*> supportCards;
	StartGameButton* startGameButton;

	TextureManager* textureManager;
	AudioManager* audioManager;

	std::unordered_map<UserType, UserEvent> users;
	std::unordered_map<UserType, Character*> characters;
	std::unordered_map<UserType, HealthBarCharacter*> healthBars;
	std::unordered_map<UserType, UltComponent*> ultProgressBars;
	TimerComponent* timerComponent;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	std::unordered_map<UserType, SupportType> chosedSupports;
	std::unordered_map<UserType, CharacterType> chosedCharacters;

	void unselectAll();
};