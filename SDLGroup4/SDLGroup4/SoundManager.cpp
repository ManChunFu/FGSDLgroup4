#include "SoundManager.h"
#include <SDL_mixer.h>
#include <iostream>
namespace Engine {
	void SoundManager::PlaySoundEffect(Mix_Chunk* sound)
	{
		Mix_PlayChannel(-1, sound, 0);
	}
	Mix_Chunk* SoundManager::GetSound(const char* _path)
	{
		return Mix_LoadWAV(_path);
	}
}