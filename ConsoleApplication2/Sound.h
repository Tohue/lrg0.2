#ifndef SOUND_H
#define SOUND_H
#include "SDL.h"
#include "SDL_mixer.h"
#include "builder.h"
#include "charactercontroller.h"
#include <string>


class CharacterController;

class Sound
{
private:
	Mix_Chunk *sound = NULL;
public:
	friend class SoundManager;
};


class SoundManager

{

private:
	bool playing = false;
public:
	Sound* Sounds[10];
	Mix_Music* Music[10];
	SoundManager();
	Sound* NewSound(std::string* file);
	bool PlaySound(Sound* sound, int channel);
	void StopSounds();
	void PlaySpecificSound(int number);
	void UpdateSounds(Builder* builder, CharacterController* charcont, Input* input);
};






#endif