#include "SoundManager.h"
#include <SDL_mixer.h>
#include <iostream>
#include <cassert>
namespace Engine {
	Mix_Music* SoundManager::music;
	SoundEffects SoundManager::soundeffects;
	void SoundManager::PlaySoundEffect(std::string soundName, int loops, int volume)
	{
		PlaySoundEffect(soundName, loops, volume, -1);
	}
	void SoundManager::PlaySoundEffect(std::string soundName, int loops, int volume, int channel)
	{
		Mix_Volume(channel, volume);
		if (HasSoundEffect(soundName))
		{
			Mix_PlayChannel(channel, soundeffects.find(soundName)->second, loops);
		}
	}
	void SoundManager::SetMusic(const char* _path, int volume)
	{
		Mix_FreeMusic(music);
		music = Mix_LoadMUS(_path);
		Mix_VolumeMusic(volume);
		if(music) Mix_PlayMusic(music, -1);
	}
	bool SoundManager::AddSoundEffect(const std::string& name, const char* _path)
	{
		assert(!name.empty());
		Mix_Chunk* sound = Mix_LoadWAV(_path);
		assert(sound);
		if (HasSoundEffect(name))
		{ return false; }
		soundeffects.insert({ name, sound });
		return true;
	}
	bool SoundManager::HasSoundEffect(const std::string& name)
	{
		auto it = soundeffects.find(name);
		if (it != soundeffects.end()) {
			return true;
		}
		return false;
	}
	void SoundManager::Shutdown()
	{
		Mix_FreeMusic(music);
		music = nullptr;
		
		for (auto it = soundeffects.begin(); it != soundeffects.end(); it++)
		{ Mix_FreeChunk(it->second); }
		soundeffects.clear();
	}
}