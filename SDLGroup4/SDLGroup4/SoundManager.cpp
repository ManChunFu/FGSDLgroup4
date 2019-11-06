#include "SoundManager.h"
#include <SDL_mixer.h>
#include <iostream>
namespace Engine {
	Mix_Music* SoundManager::music;
	void SoundManager::PlaySoundEffect(Mix_Chunk* sound, int loops, int volume)
	{
		Mix_Volume(-1, volume);
		Mix_PlayChannel(-1, sound, 0);
	}
	Mix_Chunk* SoundManager::GetSound(const char* _path)
	{
		return Mix_LoadWAV(_path);
	}
	void SoundManager::SetMusic(const char* _path, int volume)
	{
		Mix_FreeMusic(music);
		music = Mix_LoadMUS(_path);
		Mix_VolumeMusic(volume);
		if(music) Mix_PlayMusic(music, -1);
	}
}