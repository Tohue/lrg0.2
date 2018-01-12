#ifndef SOUND_H
#define SOUND_H
#include "SDL.h"
#include "SDL_mixer.h"
#include "builder.h"
#include "charactercontroller.h"
#include <string>


class CharacterController;


/*!
\brief Object that contains a sound file
*/

class Sound
{
private:
	Mix_Chunk *sound = NULL;
public:
	friend class SoundManager;
};

/*!
\brief The manager of sounds
Manages the sounds, ordering them, playing them, stopping them and so on.
*/
class SoundManager

{

private:
	bool playing = false;
public:
	Sound* Sounds[10]; ///< An asset with all sounds
	Mix_Music* Music[10]; ///< An asset with all Music
	/*!
	\brief constructor loads every sound and music file into assets
	*/
	SoundManager();
	/*!
	\brief creates new sound
	\param[in] file - a string which should be a path to the soundfile
	*/
	Sound* NewSound(std::string* file);
	/*!
	\brief plays the sound on the specific channel
	\param[in] sound - what sound to play
	\param[in] channel - where it should be played
	*/
	bool PlaySound(Sound* sound, int channel);
	/*!
	\brief stops every sound
	*/
	void StopSounds();
	/*!
	\brief plays the sound by its number
	\param[in] number - the number of sound
	*/
	void PlaySpecificSound(int number);
	/*!
	\brief updates the sound controls
	\param[in] charcont - Character Controller to check what's up with runner
	\param[in] input - To check if player is pressing something
	*/
	void UpdateSounds(Builder* builder, CharacterController* charcont, Input* input);
};






#endif