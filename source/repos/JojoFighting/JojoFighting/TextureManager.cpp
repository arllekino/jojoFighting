#include <SFML/Graphics.hpp>

#include "TextureManager.h"
#include "ActionType.h"
#include "ActionTexturesMap.h"

#include <iostream>

TextureManager::TextureManager()
{
	initCharacterSprites();
	initCharactersTexturesFromSprites();
	initStandSprites();
	initStandsTexturesFromSprites();
	initSupportSpites();
	initSupportTextures();
}

TextureManager::~TextureManager()
{
}

ActionPathMap TextureManager::getCharacterSpritePath(CharacterType type)
{
	return characterSpritesPaths[type];
}

ActionPathMap TextureManager::getStandSpritePath(StandType type)
{
	return standSpritesPaths[type];
}

ActionTexturesMap TextureManager::getCharacterTextures(CharacterType type)
{
	return charactersTextures[type];
}

ActionTexturesMap TextureManager::getStandTextures(StandType type)
{
	return standsTextures[type];
}

std::vector<sf::Texture> TextureManager::getSupportTexture(SupportType supportType)
{
	return supportTextures[supportType];
}

void TextureManager::initCharacterSprites()
{
	characterSpritesPaths[jotaro][onStay] = "assets/jotaro/JotaroStay.png";//
	characterSpritesPaths[jotaro][onGoing] = "assets/jotaro/JotaroGoingForward.png";//
	characterSpritesPaths[jotaro][onArmMediumAttack] = "assets/jotaro/JotaroMediumArmAttack.png";//
	characterSpritesPaths[jotaro][onHitedHeadStraight] = "assets/jotaro/JotaroGetArmMediumAttack.png";//
	characterSpritesPaths[jotaro][onCrouch] = "assets/jotaro/JotaroCrouch.png";//
	characterSpritesPaths[jotaro][onStandingFromCrouch] = "assets/jotaro/JotaroStandingFromCrouch.png";
	characterSpritesPaths[jotaro][onStandAttackUp] = "assets/jotaro/JotaroStandAttackUp.png";//
	characterSpritesPaths[jotaro][onSummon] = "assets/jotaro/JotaroSummonStand.png";//
	characterSpritesPaths[jotaro][onCrouchAttackForward] = "assets/jotaro/JotaroCrouchAttackForward.png";//
	characterSpritesPaths[jotaro][onCrouchPowerfulAttackForward] = "assets/jotaro/JotaroCrouchPowerfulAttack.png";//
	characterSpritesPaths[jotaro][onStandAttackDown] = "assets/jotaro/JotaroStandAttackDown.png";
	characterSpritesPaths[jotaro][onHitedLegStraight] = "assets/jotaro/JotaroHitedLegStraight.png";//
	characterSpritesPaths[jotaro][onUlt] = "assets/jotaro/JotaroTheWolrd.png";//
	characterSpritesPaths[jotaro][onHitedTorsoDownUp] = "assets/jotaro/JotaroHitedTorsoDownUp.png";
	characterSpritesPaths[jotaro][onHaha] = "assets/jotaro/JotaroHaha.png";
	characterSpritesPaths[jotaro][atDeath] = "assets/jotaro/JotaroAtDeath.png";
	characterSpritesPaths[jotaro][onJump] = "assets/jotaro/JotaroJump.png";

	characterSpritesPaths[dio][onStay] = "assets/dio/DioStay.png";
	characterSpritesPaths[dio][onGoing] = "assets/dio/DioGoingForward.png";
	characterSpritesPaths[dio][onStandAttackUp] = "assets/dio/DioStandAttackUp.png";
	characterSpritesPaths[dio][onCrouch] = "assets/dio/DioCrouch.png";
	characterSpritesPaths[dio][onArmMediumAttack] = "assets/dio/DioMediumArmAttack.png";
	characterSpritesPaths[dio][onUlt] = "assets/dio/DioTheWorld.png";
	characterSpritesPaths[dio][onSummon] = "assets/dio/DioSummonStand.png";
	characterSpritesPaths[dio][onCrouchAttackForward] = "assets/dio/DioCrouchAttackForward.png";
	characterSpritesPaths[dio][onHitedLegStraight] = "assets/dio/DioHitedLegStraight.png";
	characterSpritesPaths[dio][onCrouchPowerfulAttackForward] = "assets/dio/DioCrouchAttackup.png";
	characterSpritesPaths[dio][onStandAttackDown] = "assets/dio/DioAttackHighLeg.png";
	characterSpritesPaths[dio][onHitedHeadStraight] = "assets/dio/DioHitedHeadStraight.png";
	characterSpritesPaths[dio][onHitedTorsoDownUp] = "assets/dio/DioHitedTorsoDownUp.png";
	characterSpritesPaths[dio][onHaha] = "assets/dio/DioHaha.png";
	characterSpritesPaths[dio][onJump] = "assets/dio/DioJump.png";
}

void TextureManager::initCharactersTexturesFromSprites()
{
	charactersTextures[jotaro][onStay] = setTexturesByImagePath(characterSpritesPaths[jotaro][onStay]);
	charactersTextures[jotaro][onGoing] = setTexturesByImagePath(characterSpritesPaths[jotaro][onGoing]);
	charactersTextures[jotaro][onArmMediumAttack] = setTexturesByImagePath(characterSpritesPaths[jotaro][onArmMediumAttack]);
	charactersTextures[jotaro][onSummon] = setTexturesByImagePath(characterSpritesPaths[jotaro][onSummon]);
	charactersTextures[jotaro][onCrouch] = setTexturesByImagePath(characterSpritesPaths[jotaro][onCrouch]);
	charactersTextures[jotaro][onStandingFromCrouch] = setTexturesByImagePath(characterSpritesPaths[jotaro][onStandingFromCrouch]);
	charactersTextures[jotaro][onStandAttackUp] = setTexturesByImagePath(characterSpritesPaths[jotaro][onStandAttackUp]);
	charactersTextures[jotaro][onStandAttackDown] = setTexturesByImagePath(characterSpritesPaths[jotaro][onStandAttackDown]);
	charactersTextures[jotaro][onCrouchAttackForward] = setTexturesByImagePath(characterSpritesPaths[jotaro][onCrouchAttackForward]);
	charactersTextures[jotaro][onCrouchPowerfulAttackForward] = setTexturesByImagePath(characterSpritesPaths[jotaro][onCrouchPowerfulAttackForward]);
	charactersTextures[jotaro][onHitedHeadStraight] = setTexturesByImagePath(characterSpritesPaths[jotaro][onHitedHeadStraight]);
	charactersTextures[jotaro][onHitedLegStraight] = setTexturesByImagePath(characterSpritesPaths[jotaro][onHitedLegStraight]);
	charactersTextures[jotaro][onUlt] = setTexturesByImagePath(characterSpritesPaths[jotaro][onUlt]);
	charactersTextures[jotaro][onHitedTorsoDownUp] = setTexturesByImagePath(characterSpritesPaths[jotaro][onHitedTorsoDownUp]);
	charactersTextures[jotaro][onHaha] = setTexturesByImagePath(characterSpritesPaths[jotaro][onHaha]);
	charactersTextures[jotaro][atDeath] = setTexturesByImagePath(characterSpritesPaths[jotaro][atDeath]);
	charactersTextures[jotaro][onJump] = setTexturesByImagePath(characterSpritesPaths[jotaro][onJump]);

	charactersTextures[dio][onStay] = setTexturesByImagePath(characterSpritesPaths[dio][onStay]);
	charactersTextures[dio][onGoing] = setTexturesByImagePath(characterSpritesPaths[dio][onGoing]);
	charactersTextures[dio][onStandAttackUp] = setTexturesByImagePath(characterSpritesPaths[dio][onStandAttackUp]);
	charactersTextures[dio][onCrouch] = setTexturesByImagePath(characterSpritesPaths[dio][onCrouch]);
	charactersTextures[dio][onArmMediumAttack] = setTexturesByImagePath(characterSpritesPaths[dio][onArmMediumAttack]);
	charactersTextures[dio][onSummon] = setTexturesByImagePath(characterSpritesPaths[dio][onSummon]);
	charactersTextures[dio][onCrouchAttackForward] = setTexturesByImagePath(characterSpritesPaths[dio][onCrouchAttackForward]);
	charactersTextures[dio][onUlt] = setTexturesByImagePath(characterSpritesPaths[dio][onUlt]);
	charactersTextures[dio][onHitedLegStraight] = setTexturesByImagePath(characterSpritesPaths[dio][onHitedLegStraight]);
	charactersTextures[dio][onCrouchPowerfulAttackForward] = setTexturesByImagePath(characterSpritesPaths[dio][onCrouchPowerfulAttackForward]);
	charactersTextures[dio][onStandAttackDown] = setTexturesByImagePath(characterSpritesPaths[dio][onStandAttackDown]);
	charactersTextures[dio][onHitedHeadStraight] = setTexturesByImagePath(characterSpritesPaths[dio][onHitedHeadStraight]);
	charactersTextures[dio][onHitedTorsoDownUp] = setTexturesByImagePath(characterSpritesPaths[dio][onHitedTorsoDownUp]);
	charactersTextures[dio][onHaha] = setTexturesByImagePath(characterSpritesPaths[dio][onHaha]);
	charactersTextures[dio][onJump] = setTexturesByImagePath(characterSpritesPaths[dio][onJump]);
}

void TextureManager::initStandSprites()
{
	standSpritesPaths[starPlatinum][onStay] = "assets/jotaro/JotaroStandStay.png";
	standSpritesPaths[starPlatinum][onOraOra] = "assets/jotaro/StarPlatinumOra1.png";

	standSpritesPaths[theWorld][onOraOra] = "assets/dio/TheWorldStay.png";
	standSpritesPaths[theWorld][onOraOra] = "assets/dio/TheWorldMuda1.png";
}

void TextureManager::initStandsTexturesFromSprites()
{
	standsTextures[starPlatinum][onStay] = setTexturesByImagePath(standSpritesPaths[starPlatinum][onStay]);
	standsTextures[starPlatinum][onOraOra] = setTexturesByImagePath(standSpritesPaths[starPlatinum][onOraOra]);
	addStandTexturesByPath(starPlatinum, onOraOra, "assets/jotaro/StarPlatinumOra2.png");
	addStandTexturesByPath(starPlatinum, onOraOra, "assets/jotaro/StarPlatinumOra3.png");
	addStandTexturesByPath(starPlatinum, onOraOra, "assets/jotaro/StarPlatinumOra4.png");
	addStandTexturesByPath(starPlatinum, onOraOra, "assets/jotaro/StarPlatinumOra5.png");


	standsTextures[theWorld][onStay] = setTexturesByImagePath(standSpritesPaths[theWorld][onOraOra]);
	standsTextures[theWorld][onOraOra] = setTexturesByImagePath(standSpritesPaths[starPlatinum][onOraOra]);
	addStandTexturesByPath(theWorld, onOraOra, "assets/dio/TheWorldMuda2.png");
	addStandTexturesByPath(theWorld, onOraOra, "assets/dio/TheWorldMuda3.png");
	addStandTexturesByPath(theWorld, onOraOra, "assets/dio/TheWorldMuda4.png");
	addStandTexturesByPath(theWorld, onOraOra, "assets/dio/TheWorldMuda5.png");
}

void TextureManager::initSupportSpites()
{
	supportSptirePath[josuke] = "assets/josuke/josuke.png";
	supportSptirePath[kakyoin] = "assets/kakyoin/kakyoin.png";
	supportSptirePath[kira] = "assets/kira/kira.png";
}

void TextureManager::initSupportTextures()
{
	sf::Texture textureKakyoin;
	textureKakyoin.loadFromFile(supportSptirePath[kakyoin]);
	supportTextures[kakyoin].push_back(textureKakyoin);

	sf::Texture textureJosuke;
	textureJosuke.loadFromFile(supportSptirePath[josuke]);
	supportTextures[josuke].push_back(textureJosuke);

	sf::Texture textureKira;
	textureKira.loadFromFile(supportSptirePath[kira]);
	supportTextures[kira].push_back(textureKira);
}

void TextureManager::addStandTexturesByPath(StandType standType, ActionType actionType, std::string path)
{
	auto newTextures = setTexturesByImagePath(path);

	for (auto& newTexture : newTextures)
	{
		standsTextures[standType][actionType].push_back(newTexture);
	}
}

std::vector<sf::Texture> TextureManager::setTexturesByImagePath(std::string path)
{
	std::vector<sf::Texture> currentTextures;
	
	sf::Texture texture;
	if (!texture.loadFromFile(path))
	{
		return currentTextures;
	}

	sf::Image image = texture.copyToImage();
	auto columnHeight = image.getSize().y;

	int startX = 0;
	int endX = 0;
	int startY = 0;
	int endY = 0;

	bool isColumnEmpty = true;
	for (int x = 0; x < image.getSize().x; ++x)
	{
		isColumnEmpty = true;
		for (int y = 0; y < columnHeight; ++y)
		{
			sf::Color color = image.getPixel(x, y);
			if (color != sf::Color(128, 128, 255))
			{
				isColumnEmpty = false;
				if (startX == 0)
					startX = x;

				if (startY == 0 || y < startY)
					startY = y;

				if (endY == 0 || y > endY)
					endY = y;
			}
		}
		if (isColumnEmpty && startX != 0 && endX == 0)
		{
			endX = x;
			sf::IntRect rect(startX, startY, endX - startX, endY - startY);
			sf::Texture frameTexture;
			sf::Image image;

			image = texture.copyToImage();
			image.createMaskFromColor(sf::Color(128, 128, 255));

			frameTexture.loadFromImage(image, rect);
			currentTextures.push_back(frameTexture);

			startX = 0;
			endX = 0;
			startY = 0;
			endY = 0;
		}
	}

	return currentTextures;
}