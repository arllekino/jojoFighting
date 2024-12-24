#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include "StandType.h"
#include "CharacterType.h"
#include "ActionType.h"
#include "ActionTexturesMap.h"
#include "StandActionMap.h"
#include "CharacterActionMap.h"
#include "ActionPathMap.h"
#include "SupportType.h"

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	ActionPathMap getCharacterSpritePath(CharacterType type);
	ActionPathMap getStandSpritePath(StandType type);

	ActionTexturesMap getCharacterTextures(CharacterType type);
	ActionTexturesMap getStandTextures(StandType type);

	std::vector<sf::Texture> getSupportTexture(SupportType supportType);

private:
	CharacterActionMap characterSpritesPaths;
	StandActionMap standSpritesPaths;
	std::unordered_map<SupportType, std::string> supportSptirePath;

	std::unordered_map<CharacterType, ActionTexturesMap> charactersTextures;
	std::unordered_map<StandType, ActionTexturesMap> standsTextures;
	std::unordered_map<SupportType, std::vector<sf::Texture>> supportTextures;

	void initCharacterSprites();
	void initStandSprites();
	void initCharactersTexturesFromSprites();
	void initStandsTexturesFromSprites();
	void initSupportSpites();
	void initSupportTextures();
	void addStandTexturesByPath(StandType standType, ActionType actionType, std::string path);

	std::vector<sf::Texture> setTexturesByImagePath(std::string path);
};