#pragma once

#include <SFML/Graphics.hpp>

#include "UserType.h"
#include "CharacterType.h"
#include "SupportType.h"

class CharacterCard
{
public:
	CharacterCard(CharacterType characterType, std::string path, std::string placeholderText, sf::Color backgroundColorMask);
	CharacterCard(SupportType supportType, std::string path, std::string placeholderText);
	~CharacterCard();

	sf::Vector2f getSize();
	void setTextureByPath(std::string path, float cardScale, sf::Color colorMask);
	void setPosition(sf::Vector2f position);
	sf::RectangleShape getCardAsRect();
	sf::Text getPlaceholderText();
	void makeCardSelected(UserType user);
	void makeCardUnselected();
	void makeCardHovered();
	void makeCardUnhovered();

private:
	const float scale = 1.5f;
	const sf::Vector2f supportCardSize = { 200, 250 };

	sf::RectangleShape rect;
	sf::Texture texture;
	sf::Text text;
	sf::Font font;
	bool selected = false;
	CharacterType characterType;
	SupportType supportType;

	std::string getCharacterTypeString();
};