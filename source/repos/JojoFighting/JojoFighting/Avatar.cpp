#include "Avatar.h"

Avatar::Avatar(sf::Vector2f position, TextureManager* textureManager, CharacterType characterType, UserType userType)
{
	texture = textureManager->getCharacterTextures(characterType)[avatar][0];
	auto newSize = texture.getSize();

	rect.setPosition(position);
	rect.setSize(sf::Vector2f( newSize.x, newSize.y ));
	rect.setTexture(&texture, true);

	if (userType == secondUser) {
		rect.setScale(-1, 1);
	}
}

Avatar::~Avatar()
{
}

sf::RectangleShape Avatar::getAsShape()
{
	return rect;
}