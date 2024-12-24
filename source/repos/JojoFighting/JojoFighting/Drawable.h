#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

#include "UserType.h"
#include "UserEvent.h"
#include "Character.h"
#include "CharacterCard.h"
#include "StartGameButton.h"
#include "HealthBarCharacter.h"
#include "TimerComponent.h"
#include "UltComponent.h"

class Drawable
{
public:
	Drawable();
	~Drawable();

	void drawMenu(sf::RenderWindow& window, sf::Sprite& background, std::vector<CharacterCard*>, std::vector<CharacterCard*> supportCards, StartGameButton* startGameButton);
	void drawGame(
		sf::RenderWindow& window,
		sf::Sprite& background,
		std::unordered_map<UserType, UserEvent>& users,
		std::unordered_map<UserType, Character*> characters,
		std::unordered_map<UserType, HealthBarCharacter*> healthBars,
		std::unordered_map<UserType, UltComponent*> ultProgressBars,
		TimerComponent* timer
	);

private:
	void toCoverBackgroundGame(sf::Sprite& background, sf::Vector2u windowSize, UserEvent userEvent, sf::RectangleShape shape);
	void toCoverBackground(sf::Sprite& background, sf::Vector2u windowSize);
	void drawAbility(sf::RenderWindow& window, std::vector<sf::CircleShape> ability);
};