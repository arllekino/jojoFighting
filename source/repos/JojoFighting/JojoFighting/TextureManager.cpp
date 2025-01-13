#include <SFML/Graphics.hpp>

#include "TextureManager.h"
#include "ActionType.h"
#include "ActionTexturesMap.h"

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
	characterSpritesPaths[jotaro][onWin] = "assets/jotaro/JotaroWin.png";
	characterSpritesPaths[jotaro][onWinCycle] = "assets/jotaro/JotaroWinCycle.png";
	characterSpritesPaths[jotaro][avatar] = "assets/jotaro/JotaroAvatar.png";
	characterSpritesPaths[jotaro][onHitedInJump] = "assets/jotaro/JotaroHitedInJump.png";
	characterSpritesPaths[jotaro][onHitedHeadDownUp] = "assets/jotaro/JotaroHitedBody.png";

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
	characterSpritesPaths[dio][atDeath] = "assets/dio/DioAtDeath.png";
	characterSpritesPaths[dio][onWin] = "assets/dio/DioWin.png";
	characterSpritesPaths[dio][onWinCycle] = "assets/dio/DioWinCycle.png";
	characterSpritesPaths[dio][avatar] = "assets/dio/DioAvatar.png";
	characterSpritesPaths[dio][onHitedInJump] = "assets/dio/DioHitedInJump.png";
	characterSpritesPaths[dio][onHitedHeadDownUp] = "assets/dio/DioHitedHead.png";

	characterSpritesPaths[joseph][onStay] = "assets/joseph/JosephStay.png";
	characterSpritesPaths[joseph][onGoing] = "assets/joseph/JosephGoing.png";
	characterSpritesPaths[joseph][onArmMediumAttack] = "assets/joseph/JosephMediumArmAttack.png";
	characterSpritesPaths[joseph][onJump] = "assets/joseph/JosephJump.png";
	characterSpritesPaths[joseph][onCrouch] = "assets/joseph/JosephCrouch.png";
	characterSpritesPaths[joseph][onCrouchAttackForward] = "assets/joseph/JosephCrounchAttackForward.png";
	characterSpritesPaths[joseph][onStandAttackDown] = "assets/joseph/JosephHamon1.png";
	characterSpritesPaths[joseph][onHaha] = "assets/joseph/JosephOMG.png";
	characterSpritesPaths[joseph][onStandAttackUp] = "assets/joseph/JosephStandAttackUp.png";
	characterSpritesPaths[joseph][onSummon] = "assets/joseph/JosephSummonStand.png";
	characterSpritesPaths[joseph][onCrouchPowerfulAttackForward] = "assets/joseph/JosephCrouchPowerful.png";
	characterSpritesPaths[joseph][onUlt] = "assets/joseph/JosephUlt1.png";
	characterSpritesPaths[joseph][onHitedLegStraight] = "assets/joseph/JosephHitedLeg.png";
	characterSpritesPaths[joseph][onHitedHeadStraight] = "assets/joseph/JosephHitedHeadStraight.png";
	//characterSpritesPaths[joseph][onHitedHeadDownUp] = "assets/joseph/JosephHitedTorso.png";
	characterSpritesPaths[joseph][atDeath] = "assets/joseph/JosephAtDeath1.png";
	characterSpritesPaths[joseph][onWin] = "assets/joseph/JosephWin.png";
	characterSpritesPaths[joseph][onWinCycle] = "assets/joseph/JosephWinCycle.png";
	characterSpritesPaths[joseph][avatar] = "assets/joseph/JosephAvatar.png";
	characterSpritesPaths[joseph][onHitedInJump] = "assets/joseph/JosephHitedInJump.png";
	characterSpritesPaths[joseph][onHitedHeadDownUp] = "assets/joseph/JosephHitedHead.png";
}

void TextureManager::initCharactersTexturesFromSprites()
{
	charactersTextures[jotaro][onStay] = setTexturesByImagePath(characterSpritesPaths[jotaro][onStay], blueColorMask);
	charactersTextures[jotaro][onGoing] = setTexturesByImagePath(characterSpritesPaths[jotaro][onGoing], blueColorMask);
	charactersTextures[jotaro][onArmMediumAttack] = setTexturesByImagePath(characterSpritesPaths[jotaro][onArmMediumAttack], blueColorMask);
	charactersTextures[jotaro][onSummon] = setTexturesByImagePath(characterSpritesPaths[jotaro][onSummon], blueColorMask);
	charactersTextures[jotaro][onCrouch] = setTexturesByImagePath(characterSpritesPaths[jotaro][onCrouch], blueColorMask);
	charactersTextures[jotaro][onStandingFromCrouch] = setTexturesByImagePath(characterSpritesPaths[jotaro][onStandingFromCrouch], blueColorMask);
	charactersTextures[jotaro][onStandAttackUp] = setTexturesByImagePath(characterSpritesPaths[jotaro][onStandAttackUp], blueColorMask);
	charactersTextures[jotaro][onStandAttackDown] = setTexturesByImagePath(characterSpritesPaths[jotaro][onStandAttackDown], blueColorMask);
	charactersTextures[jotaro][onCrouchAttackForward] = setTexturesByImagePath(characterSpritesPaths[jotaro][onCrouchAttackForward], blueColorMask);
	charactersTextures[jotaro][onCrouchPowerfulAttackForward] = setTexturesByImagePath(characterSpritesPaths[jotaro][onCrouchPowerfulAttackForward], blueColorMask);
	charactersTextures[jotaro][onHitedHeadStraight] = setTexturesByImagePath(characterSpritesPaths[jotaro][onHitedHeadStraight], blueColorMask);
	charactersTextures[jotaro][onHitedLegStraight] = setTexturesByImagePath(characterSpritesPaths[jotaro][onHitedLegStraight], blueColorMask);
	charactersTextures[jotaro][onUlt] = setTexturesByImagePath(characterSpritesPaths[jotaro][onUlt], blueColorMask);
	charactersTextures[jotaro][onHitedTorsoDownUp] = setTexturesByImagePath(characterSpritesPaths[jotaro][onHitedTorsoDownUp], blueColorMask);
	charactersTextures[jotaro][onHaha] = setTexturesByImagePath(characterSpritesPaths[jotaro][onHaha], blueColorMask);
	charactersTextures[jotaro][atDeath] = setTexturesByImagePath(characterSpritesPaths[jotaro][atDeath], blueColorMask);
	charactersTextures[jotaro][onJump] = setTexturesByImagePath(characterSpritesPaths[jotaro][onJump], blueColorMask);
	charactersTextures[jotaro][onWin] = setTexturesByImagePath(characterSpritesPaths[jotaro][onWin], blueColorMask);
	charactersTextures[jotaro][onWinCycle] = setTexturesByImagePath(characterSpritesPaths[jotaro][onWinCycle], blueColorMask);
	charactersTextures[jotaro][avatar] = setTexturesByImagePath(characterSpritesPaths[jotaro][avatar], blueColorMask);
	charactersTextures[jotaro][onHitedInJump] = setTexturesByImagePath(characterSpritesPaths[jotaro][onHitedInJump], blueColorMask);
	charactersTextures[jotaro][onHitedHeadDownUp] = setTexturesByImagePath(characterSpritesPaths[jotaro][onHitedHeadDownUp], blueColorMask);

	charactersTextures[dio][onStay] = setTexturesByImagePath(characterSpritesPaths[dio][onStay], blueColorMask);
	charactersTextures[dio][onGoing] = setTexturesByImagePath(characterSpritesPaths[dio][onGoing], blueColorMask);
	charactersTextures[dio][onStandAttackUp] = setTexturesByImagePath(characterSpritesPaths[dio][onStandAttackUp], blueColorMask);
	charactersTextures[dio][onCrouch] = setTexturesByImagePath(characterSpritesPaths[dio][onCrouch], blueColorMask);
	charactersTextures[dio][onArmMediumAttack] = setTexturesByImagePath(characterSpritesPaths[dio][onArmMediumAttack], blueColorMask);
	charactersTextures[dio][onSummon] = setTexturesByImagePath(characterSpritesPaths[dio][onSummon], blueColorMask);
	charactersTextures[dio][onCrouchAttackForward] = setTexturesByImagePath(characterSpritesPaths[dio][onCrouchAttackForward], blueColorMask);
	charactersTextures[dio][onUlt] = setTexturesByImagePath(characterSpritesPaths[dio][onUlt], blueColorMask);
	charactersTextures[dio][onHitedLegStraight] = setTexturesByImagePath(characterSpritesPaths[dio][onHitedLegStraight], blueColorMask);
	charactersTextures[dio][onCrouchPowerfulAttackForward] = setTexturesByImagePath(characterSpritesPaths[dio][onCrouchPowerfulAttackForward], blueColorMask);
	charactersTextures[dio][onStandAttackDown] = setTexturesByImagePath(characterSpritesPaths[dio][onStandAttackDown], blueColorMask);
	charactersTextures[dio][onHitedHeadStraight] = setTexturesByImagePath(characterSpritesPaths[dio][onHitedHeadStraight], blueColorMask);
	charactersTextures[dio][onHitedTorsoDownUp] = setTexturesByImagePath(characterSpritesPaths[dio][onHitedTorsoDownUp], blueColorMask);
	charactersTextures[dio][onHaha] = setTexturesByImagePath(characterSpritesPaths[dio][onHaha], blueColorMask);
	charactersTextures[dio][onJump] = setTexturesByImagePath(characterSpritesPaths[dio][onJump], blueColorMask);
	charactersTextures[dio][atDeath] = setTexturesByImagePath(characterSpritesPaths[dio][atDeath], blueColorMask);
	charactersTextures[dio][onWin] = setTexturesByImagePath(characterSpritesPaths[dio][onWin], blueColorMask);
	charactersTextures[dio][onWinCycle] = setTexturesByImagePath(characterSpritesPaths[dio][onWinCycle], blueColorMask);
	charactersTextures[dio][avatar] = setTexturesByImagePath(characterSpritesPaths[dio][avatar], blueColorMask);
	charactersTextures[dio][onHitedInJump] = setTexturesByImagePath(characterSpritesPaths[dio][onHitedInJump], blueColorMask);
	charactersTextures[dio][onHitedHeadDownUp] = setTexturesByImagePath(characterSpritesPaths[dio][onHitedHeadDownUp], blueColorMask);

	charactersTextures[joseph][onStay] = setTexturesByImagePath(characterSpritesPaths[joseph][onStay], greenColorMask);
	charactersTextures[joseph][onGoing] = setTexturesByImagePath(characterSpritesPaths[joseph][onGoing], greenColorMask);
	charactersTextures[joseph][onArmMediumAttack] = setTexturesByImagePath(characterSpritesPaths[joseph][onArmMediumAttack], greenColorMask);
	charactersTextures[joseph][onJump] = setTexturesByImagePath(characterSpritesPaths[joseph][onJump], greenColorMask);
	charactersTextures[joseph][onCrouch] = setTexturesByImagePath(characterSpritesPaths[joseph][onCrouch], greenColorMask);
	charactersTextures[joseph][onCrouchAttackForward] = setTexturesByImagePath(characterSpritesPaths[joseph][onCrouchAttackForward], greenColorMask);
	charactersTextures[joseph][onStandAttackDown] = setTexturesByImagePath(characterSpritesPaths[joseph][onStandAttackDown], greenColorMask);
	addCharacterTexturesByPath(joseph, onStandAttackDown, "assets/joseph/JosephHamon2.png", greenColorMask);
	addCharacterTexturesByPath(joseph, onStandAttackDown, "assets/joseph/JosephHamon3.png", greenColorMask);
	charactersTextures[joseph][onHaha] = setTexturesByImagePath(characterSpritesPaths[joseph][onHaha], greenColorMask);
	charactersTextures[joseph][onStandAttackUp] = setTexturesByImagePath(characterSpritesPaths[joseph][onStandAttackUp], greenColorMask);
	charactersTextures[joseph][onSummon] = setTexturesByImagePath(characterSpritesPaths[joseph][onSummon], greenColorMask);
	charactersTextures[joseph][onCrouchPowerfulAttackForward] = setTexturesByImagePath(characterSpritesPaths[joseph][onCrouchPowerfulAttackForward], greenColorMask);
	charactersTextures[joseph][onUlt] = setTexturesByImagePath(characterSpritesPaths[joseph][onUlt], greenColorMask);
	addCharacterTexturesByPath(joseph, onUlt, "assets/joseph/JosephUlt2.png", greenColorMask);
	charactersTextures[joseph][onHitedLegStraight] = setTexturesByImagePath(characterSpritesPaths[joseph][onHitedLegStraight], greenColorMask);
	charactersTextures[joseph][onHitedHeadStraight] = setTexturesByImagePath(characterSpritesPaths[joseph][onHitedHeadStraight], greenColorMask);
	charactersTextures[joseph][onHitedTorsoDownUp] = setTexturesByImagePath(characterSpritesPaths[joseph][onHitedHeadDownUp], greenColorMask);
	charactersTextures[joseph][atDeath] = setTexturesByImagePath(characterSpritesPaths[joseph][atDeath], greenColorMask);
	addCharacterTexturesByPath(joseph, atDeath, "assets/joseph/JosephAtDeath2.png", greenColorMask);
	addCharacterTexturesByPath(joseph, atDeath, "assets/joseph/JosephAtDeath3.png", greenColorMask);
	charactersTextures[joseph][onWin] = setTexturesByImagePath(characterSpritesPaths[joseph][onWin], greenColorMask);
	charactersTextures[joseph][onWinCycle] = setTexturesByImagePath(characterSpritesPaths[joseph][onWinCycle], greenColorMask);
	charactersTextures[joseph][avatar] = setTexturesByImagePath(characterSpritesPaths[joseph][avatar], greenColorMask);
	charactersTextures[joseph][onHitedInJump] = setTexturesByImagePath(characterSpritesPaths[joseph][onHitedInJump], greenColorMask);
	charactersTextures[joseph][onHitedHeadDownUp] = setTexturesByImagePath(characterSpritesPaths[joseph][onHitedHeadDownUp], greenColorMask);
}

void TextureManager::initStandSprites()
{
	standSpritesPaths[starPlatinum][onStay] = "assets/jotaro/JotaroStandStay.png";
	standSpritesPaths[starPlatinum][onOraOra] = "assets/jotaro/StarPlatinumOra1.png";

	standSpritesPaths[theWorld][onStay] = "assets/dio/TheWorldStay.png";
	standSpritesPaths[theWorld][onOraOra] = "assets/dio/TheWorldMuda1.png";

	standSpritesPaths[hermitPurple][onOraOra] = "assets/joseph/JosephStandUlt.png";
}

void TextureManager::initStandsTexturesFromSprites()
{
	standsTextures[starPlatinum][onStay] = setTexturesByImagePath(standSpritesPaths[starPlatinum][onStay], blueColorMask);
	standsTextures[starPlatinum][onOraOra] = setTexturesByImagePath(standSpritesPaths[starPlatinum][onOraOra], blueColorMask);
	addStandTexturesByPath(starPlatinum, onOraOra, "assets/jotaro/StarPlatinumOra2.png", blueColorMask);
	addStandTexturesByPath(starPlatinum, onOraOra, "assets/jotaro/StarPlatinumOra3.png", blueColorMask);
	addStandTexturesByPath(starPlatinum, onOraOra, "assets/jotaro/StarPlatinumOra4.png", blueColorMask);
	addStandTexturesByPath(starPlatinum, onOraOra, "assets/jotaro/StarPlatinumOra5.png", blueColorMask);


	standsTextures[theWorld][onStay] = setTexturesByImagePath(standSpritesPaths[theWorld][onOraOra], blueColorMask);
	standsTextures[theWorld][onOraOra] = setTexturesByImagePath(standSpritesPaths[starPlatinum][onOraOra], blueColorMask);
	addStandTexturesByPath(theWorld, onOraOra, "assets/dio/TheWorldMuda2.png", blueColorMask);
	addStandTexturesByPath(theWorld, onOraOra, "assets/dio/TheWorldMuda3.png", blueColorMask);
	addStandTexturesByPath(theWorld, onOraOra, "assets/dio/TheWorldMuda4.png", blueColorMask);
	addStandTexturesByPath(theWorld, onOraOra, "assets/dio/TheWorldMuda5.png", blueColorMask);


	standsTextures[hermitPurple][onOraOra] = setTexturesByImagePath(standSpritesPaths[hermitPurple][onOraOra], greenColorMask);
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

void TextureManager::addStandTexturesByPath(StandType standType, ActionType actionType, std::string path, sf::Color colorMask)
{
	auto newTextures = setTexturesByImagePath(path, colorMask);

	for (auto& newTexture : newTextures)
	{
		standsTextures[standType][actionType].push_back(newTexture);
	}
}

void TextureManager::addCharacterTexturesByPath(CharacterType characterType, ActionType actionType, std::string path, sf::Color colorMask)
{
	auto newTextures = setTexturesByImagePath(path, colorMask);

	for (auto& newTexture : newTextures)
	{
		charactersTextures[characterType][actionType].push_back(newTexture);
	}
}

std::vector<sf::Texture> TextureManager::setTexturesByImagePath(std::string path, sf::Color colorMask)
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
			if (color != colorMask)
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
			image.createMaskFromColor(colorMask);

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