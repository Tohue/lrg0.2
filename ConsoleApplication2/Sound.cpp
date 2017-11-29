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

}

Sound* SoundManager::NewSound(std::string* file)
{
	Sound* sound = new Sound();
	sound->sound = Mix_LoadWAV(file->c_str());
	return sound;
}

bool SoundManager::PlaySound(Sound* sound)
{
	if (sound->sound == NULL) return false;

	Mix_PlayChannel(0, sound->sound, 0);
	return true;
}

void SoundManager::UpdateSounds(Builder* builder, CharacterController* charcont, Input* input)
{
	if (charcont->IsClimbing() &&  (input->KeyDown(SDL_SCANCODE_UP) || input->KeyDown(SDL_SCANCODE_DOWN)))
	{
			if (!playing)
			{
				playing = true;
				if (Mix_Paused(0)) Mix_Resume(0);
				PlaySound(Sounds[0]);
			}
	}
	else
	{
		Mix_HaltChannel(0);
		playing = false;
	}

}