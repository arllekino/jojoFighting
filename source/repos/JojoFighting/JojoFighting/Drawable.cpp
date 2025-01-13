#include "Drawable.h"

#include "CharacterCard.h"
#include "StartGameButton.h"
#include "HealthBarCharacter.h"
#include "TimerComponent.h"

#include <iostream>

Drawable::Drawable()
{
}

Drawable::~Drawable()
{
}

void Drawable::drawGame(
	sf::RenderWindow& window,
	sf::Sprite& background,
	std::unordered_map<UserType, UserEvent>& users,
	std::unordered_map<UserType, Character*> characters,
	std::unordered_map<UserType, HealthBarCharacter*> healthBars,
	std::unordered_map<UserType, UltComponent*> ultProgressBars,
	TimerComponent* timer,
	FinishHim* finishHimText
)
{
	toCoverBackground(background, window.getSize());
	toCoverBackgroundGame(background, window.getSize(), users[firstUser], characters[firstUser]->getBody().bodyShape);
	toCoverBackgroundGame(background, window.getSize(), users[secondUser], characters[secondUser]->getBody().bodyShape);

	window.clear();
	window.draw(background);

	window.draw(timer->getTimerAsShape());
	window.draw(timer->getTimeAsText());

	if (characters[firstUser]->isSupportCalled())
	{
		window.draw(characters[firstUser]->getSupportAsRect());
		drawAbility(window, characters[firstUser]->getSupportAbility());
	}
	if (characters[secondUser]->isSupportCalled())
	{
		window.draw(characters[secondUser]->getSupportAsRect());
		drawAbility(window, characters[secondUser]->getSupportAbility());
	}

	auto firstBody = characters[firstUser]->getBody();
	auto secondBody = characters[secondUser]->getBody();

	if (characters[firstUser]->isPunchGoing())
		std::swap(firstBody, secondBody);

	if (firstBody.isDrawable)
		window.draw(firstBody.bodyShape);

	if (secondBody.isDrawable)
		window.draw(secondBody.bodyShape);

	if (characters[firstUser]->isStandVisible())
		window.draw(characters[firstUser]->getStandAsShape());

	if (characters[secondUser]->isStandVisible())
		window.draw(characters[secondUser]->getStandAsShape());

	if (characters[firstUser]->isEffectInProgress())
		window.draw(characters[firstUser]->getEffect());

	if (characters[secondUser]->isEffectInProgress())
		window.draw(characters[secondUser]->getEffect());


	window.draw(healthBars[firstUser]->getHealthBarAsRect());
	window.draw(healthBars[firstUser]->getWrapperAsRect());
	window.draw(healthBars[secondUser]->getHealthBarAsRect());
	window.draw(healthBars[secondUser]->getWrapperAsRect());

	window.draw(ultProgressBars[firstUser]->getAsShape());
	window.draw(ultProgressBars[firstUser]->getWrapperAsShape());
	window.draw(ultProgressBars[secondUser]->getAsShape());
	window.draw(ultProgressBars[secondUser]->getWrapperAsShape());

	window.draw(characters[firstUser]->getAvatar());
	window.draw(characters[secondUser]->getAvatar());

	if (characters[firstUser]->getHp() <= 0 || characters[secondUser]->getHp() <= 0)
	{
		window.draw(finishHimText->getText());
	}

	window.display();
}

void Drawable::drawMenu(sf::RenderWindow& window, sf::Sprite& background, std::vector<CharacterCard*> cards, std::vector<CharacterCard*> supportCards, StartGameButton* startGameButton)
{
	toCoverBackground(background, window.getSize());

	window.clear();
	window.draw(background);

	for (auto& card : cards)
	{
		window.draw(card->getCardAsRect());
		window.draw(card->getPlaceholderText());
	}

	for (auto& supportCard : supportCards)
	{
		window.draw(supportCard->getCardAsRect());
		window.draw(supportCard->getPlaceholderText());
	}

	window.draw(startGameButton->getButtonAsRect());
	window.draw(startGameButton->getPlaceholderText());

	window.display();
}

void Drawable::toCoverBackgroundGame(sf::Sprite& background, sf::Vector2u windowSize, UserEvent userEvent, sf::RectangleShape shape)
{
	if (background.getTexture() != nullptr)
	{
		const float step = 10;
		const float gap = 300;

		if (userEvent == UserEvent::onLeft || userEvent == UserEvent::onRight)
		{
			auto currentBackgroundPos = background.getPosition();
			if (shape.getPosition().x - shape.getSize().x / 2 - gap < 0)
			{
				if (currentBackgroundPos.x < 0)
					background.setPosition(currentBackgroundPos.x + step, currentBackgroundPos.y);
			}

			if (shape.getPosition().x + shape.getSize().x / 2 + gap > windowSize.x)
			{
				float maxX = windowSize.x - background.getTexture()->getSize().x * background.getScale().x;
				if (currentBackgroundPos.x > maxX)
					background.setPosition(currentBackgroundPos.x - step, currentBackgroundPos.y);
			}
		}
	}
}

void Drawable::toCoverBackground(sf::Sprite& background, sf::Vector2u windowSize)
{
	if (background.getTexture() != nullptr)
	{
		auto prevSize = background.getTexture()->getSize();
		const float scale = static_cast<float>(windowSize.y) / background.getTexture()->getSize().y;
		background.setTextureRect(sf::IntRect(0, 0, prevSize.x * scale, prevSize.y * scale));
		background.setScale(scale, scale);
	}
}

void Drawable::drawAbility(sf::RenderWindow& window, std::vector<sf::CircleShape> ability)
{
	if (ability.empty()) {
		return;
	}

	for (auto& item : ability)
	{
		window.draw(item);
	}
}