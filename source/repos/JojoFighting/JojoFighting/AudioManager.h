#pragma once

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <vector>

#include "AudioMapSounds.h"
#include "CharacterType.h"
#include "ActionType.h"
#include "AudioState.h"
#include "GameState.h"
#include "MenuUserEvent.h"

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	void playSound(CharacterType characterType, ActionType actionType);
	void playMusic(GameState gameState);
	void stopMusic();
	void pauseMusic();
	void continueMusic();
	void playMenuSound(MenuUserEvent event);

private:
	const float musicVolume = 50.f;

	AudioMapSounds soundsMap;
	sf::Sound sound;
	sf::SoundBuffer buffer;
	AudioState soundState = noneSound;

	sf::Music music;
	std::unordered_map<GameState, std::string> gameMusicMap;
	std::unordered_map<MenuUserEvent, std::string> menuMusicMap;
	AudioState musicState = noneSound;

	void initSounds();
	void initMusic();

	std::vector<ActionType> loadedAction = {
		onUlt,
		onCrouchPowerfulAttackForward
	};
};