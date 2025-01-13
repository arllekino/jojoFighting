#pragma once

#include <SFML/Graphics.hpp>

#include "CharacterType.h"
#include "TextureManager.h"
#include "UserType.h"

class Avatar
{
public:
	Avatar(sf::Vector2f position, TextureManager* textureManager, CharacterType characterType, UserType userType);
	~Avatar();

	sf::RectangleShape getAsShape();

private:
	sf::Texture texture;
	sf::RectangleShape rect;
};