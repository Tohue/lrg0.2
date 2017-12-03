#include "stdafx.h"
#include "Sound.h"

SoundManager::SoundManager()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
	std::string str = "../sounds/Runner_Climbing.wav";
	Sounds[0] = NewSound(&str);

	str = "../sounds/Gun_Fire.wav";
	Sounds[1] = NewSound(&str);

	str = "../sounds/Coin_Get.wav";
	Sounds[2] = NewSound(&str);

	str = "../sounds/Teleport_Opened.wav";
	Sounds[3] = NewSound(&str);

	str = "../sounds/Level_Clear.wav";
	Sounds[4] = NewSound(&str);

	str = "../sounds/music/1.mp3";
	Music[0] = Mix_LoadMUS((&str)->c_str());

	Mix_VolumeMusic(100);

}

Sound* SoundManager::NewSound(std::string* file)
{
	Sound* sound = new Sound();
	sound->sound = Mix_LoadWAV(file->c_str());
	return sound;
}

bool SoundManager::PlaySound(Sound* sound, int channel)
{
	if (sound->sound == NULL) return false;

	Mix_PlayChannel(channel, sound->sound, 0);
	return true;
}


void SoundManager::PlaySpecificSound(int number)
{

	PlaySound(Sounds[number], number);

}


void SoundManager::UpdateSounds(Builder* builder, CharacterController* charcont, Input* input)
{
	if (Mix_PlayingMusic() == 0) Mix_PlayMusic(Music[0], -1);
	if (charcont->IsClimbing() &&  (input->KeyDown(SDL_SCANCODE_UP) || input->KeyDown(SDL_SCANCODE_DOWN)))
	{
			if (!playing)
			{
				playing = true;
				if (Mix_Paused(0)) Mix_Resume(0);
				PlaySound(Sounds[0],0);
			}
	}
	else
	{
		Mix_HaltChannel(0);
		playing = false;
	}

	if (charcont->state == Digging && Mix_Playing(1) < 1)
	{
			PlaySound(Sounds[1],1);
	}
}