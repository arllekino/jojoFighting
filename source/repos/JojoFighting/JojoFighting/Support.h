#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "SupportType.h"
#include "TextureManager.h"
#include "Character.h"
#include "ActionType.h"

class Character;

class Support
{
public:
	Support(SupportType type, TextureManager* textureManager, sf::Vector2f newSize, sf::Vector2f newPos, int direction);
	~Support();

	bool isSupportCalled();
	sf::RectangleShape getSupportAsRect();
	SupportType getSupportType();
	std::vector<sf::CircleShape> getAbilitysShapes();
	void onCallSupport();
	void checkSupport(Character* whosOnPunch);


private:
	const sf::Time callTime = sf::seconds(5);
	const float speedEmeraldSplash = 40.f;
	const float speedKiraBubble = 5.f;
	const float speedJosukeHill = 6.f;

	sf::Clock clock;

	bool isSupportVisible = false;

	SupportType supportType;
	sf::RectangleShape supportRect;
	std::vector<sf::Texture> supportTextures;

	std::vector<sf::CircleShape> ability;

	void callSupportKakyoin();
	void callSupportJosuke();
	void callSupportKira();
	void checkCollission(Character* character);

	void setSupportTexturesPos(sf::Vector2f size, sf::Vector2f position, int xDirection);
};