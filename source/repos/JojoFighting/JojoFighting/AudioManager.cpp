#include "AudioManager.h"

#include <SFML/Audio.hpp>

#include "CharacterType.h"
#include "ActionType.h"

AudioManager::AudioManager()
{
	initSounds();
	initMusic();
}

AudioManager::~AudioManager()
{
}

void AudioManager::playSound(CharacterType characterType, ActionType actionType)
{
	if (soundState == inProgress)
	{
		if (sound.getStatus() != sf::SoundSource::Playing)
			soundState = noneSound;
		return;
	}
	else
	{
		soundState = inProgress;
	}

	buffer.loadFromFile(soundsMap[characterType][actionType]);

	sound.setBuffer(buffer);
	sound.play();
}

void AudioManager::playMusic(GameState gameState)
{
	if (musicState == inProgress)
	{
		if (sound.getStatus() != sf::SoundSource::Playing)
			soundState = noneSound;
		return;
	}
	else
	{
		musicState = inProgress;
	}

	if (!music.openFromFile(gameMusicMap[gameState]))
		return;

	music.setLoop(true);
	music.play();
}

void AudioManager::stopMusic()
{
	music.stop();
	musicState = noneSound;
}

void AudioManager::pauseMusic()
{
	if (music.getStatus() == sf::Music::Playing)
	{
		music.pause();
		musicState = paused;
	}
}

void AudioManager::continueMusic()
{
	if (musicState != inProgress && music.getStatus() != sf::Music::Playing)
	{
		music.play();
		musicState = inProgress;
	}
}

void AudioManager::playMenuSound(MenuUserEvent event)
{
	buffer.loadFromFile(menuMusicMap[event]);

	sound.setBuffer(buffer);
	sound.play();
}

void AudioManager::initSounds()
{
	soundsMap[jotaro][onUlt] = "assets/jotaro/sounds/starPlatinumTheWorld.wav";
	soundsMap[jotaro][onCrouchPowerfulAttackForward] = "assets/jotaro/sounds/superOra.wav";
	soundsMap[jotaro][onStandAttackDown] = "assets/jotaro/sounds/oneOra.wav";
	soundsMap[jotaro][onArmMediumAttack] = "assets/jotaro/sounds/lightAttack.wav";
	soundsMap[jotaro][onCrouch] = "assets/jotaro/sounds/crouch.wav";
	soundsMap[jotaro][onStandAttackUp] = "assets/jotaro/sounds/oraOraLight.wav";
	soundsMap[jotaro][onCrouchAttackForward] = "assets/jotaro/sounds/lightAttack1.wav";
	soundsMap[jotaro][onCallSupport] = "assets/jotaro/sounds/kakyoin.wav";
	soundsMap[jotaro][onHaha] = "assets/jotaro/sounds/yareYareDaze.wav";
	soundsMap[jotaro][onTakeHit] = "assets/game/sounds/hitBody.wav";
	soundsMap[jotaro][onGoing] = "assets/game/sounds/stepBoots.wav";

	soundsMap[dio][onUlt] = "assets/dio/sounds/theWorld.wav";
	soundsMap[dio][onCrouchPowerfulAttackForward] = "assets/dio/sounds/lightAttack.wav";
	soundsMap[dio][onStandAttackUp] = "assets/dio/sounds/attack.wav";
	soundsMap[dio][onArmMediumAttack] = "assets/dio/sounds/superAttack.wav";
	soundsMap[dio][onStandAttackDown] = "assets/dio/sounds/legAttack.wav";
	soundsMap[dio][onCrouch] = "assets/dio/sounds/crouch.wav";
	soundsMap[dio][onCrouchAttackForward] = "assets/dio/sounds/corroy.wav";
	soundsMap[dio][onCallSupport] = "assets/dio/sounds/killer-queen-bite-the-dust-sound-effect-made-with-Voicemod.wav";
	soundsMap[dio][onHaha] = "assets/dio/sounds/mudamuda.wav";
	soundsMap[dio][onTakeHit] = "assets/game/sounds/hitBody.wav";
	soundsMap[dio][onGoing] = "assets/game/sounds/stepBoots.wav";

	menuMusicMap[left] = "assets/game/sounds/switch.wav";
	menuMusicMap[right] = "assets/game/sounds/switch.wav";
	menuMusicMap[onToggleFirstUser] = "assets/game/sounds/select.wav";
	menuMusicMap[onToggleSecondUser] = "assets/game/sounds/select.wav";
	menuMusicMap[onEnter] = "assets/game/sounds/start.wav";
}

void AudioManager::initMusic()
{
	music.setVolume(musicVolume);
	gameMusicMap[game] = "assets/game/music/MainGameMusic.wav";
	gameMusicMap[menu] = "assets/game/music/aiaiai.wav";
}

