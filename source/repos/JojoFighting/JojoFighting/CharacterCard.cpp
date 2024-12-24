#include "CharacterCard.h"

#include <SFML/Graphics.hpp>
#include "UserType.h"

CharacterCard::CharacterCard(CharacterType characterType, std::string path, std::string placeholderText)
{
	this->characterType = characterType;
	setTextureByPath(path, scale);
	font.loadFromFile("assets/game/fonts/Bangers-Regular.ttf");
	text.setFont(font);
	text.setString(placeholderText);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::White);
}

CharacterCard::CharacterCard(SupportType supportType, std::string path, std::string placeholderText)
{
	this->supportType = supportType;
	setTextureByPath(path, 1.f);
	rect.setSize(supportCardSize);
	font.loadFromFile("assets/game/fonts/Bangers-Regular.ttf");
	text.setFont(font);
	text.setString(placeholderText);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::White);
}

CharacterCard::~CharacterCard()
{}

sf::Vector2f CharacterCard::getSize()
{
	return rect.getSize();
}

void CharacterCard::setTextureByPath(std::string path, float cardScale)
{
	sf::Texture localTexture;

	if (!localTexture.loadFromFile(path))
	{
		return;
	}

	sf::Image image = localTexture.copyToImage();
	image.createMaskFromColor(sf::Color(128, 128, 255));

	auto imageSize = image.getSize();

	rect.setSize(sf::Vector2f(imageSize.x, imageSize.y) * cardScale);
	texture.loadFromImage(image);
	rect.setTexture(&texture);
}

void CharacterCard::setPosition(sf::Vector2f position)
{
	rect.setPosition(position);
	text.setPosition(position.x, position.y + rect.getSize().y);
}

sf::RectangleShape CharacterCard::getCardAsRect()
{
	return rect;
}

sf::Text CharacterCard::getPlaceholderText()
{
	return text;
}

void CharacterCard::makeCardSelected(UserType user)
{
	auto userString = user == firstUser ? "first" : "second";
	auto characterTypeString = getCharacterTypeString();

	text.setString(characterTypeString + " " + "(selected by " + userString + " user)");
	text.setFillColor(sf::Color::Green);
	selected = true;
}

void CharacterCard::makeCardUnselected()
{
	text.setFillColor(sf::Color::Yellow);
	text.setString(getCharacterTypeString());
	selected = false;
}

void CharacterCard::makeCardHovered()
{
	if (selected)
		return;
	
	text.setFillColor(sf::Color::Yellow);
}

void CharacterCard::makeCardUnhovered()
{
	if (selected)
		return;

	text.setFillColor(sf::Color::White);
}

std::string CharacterCard::getCharacterTypeString()
{
	switch (characterType)
	{
	case jotaro:
		return "Jotaro";
	case dio:
		return "Dio";
	default:
		break;
	}

	switch (supportType)
	{
	case kakyoin:
		return "Kakyion";
	case josuke:
		return "Josuke";
	case kira:
		return "Kira Yoshikage";
	default:
		return "";
	}
}

