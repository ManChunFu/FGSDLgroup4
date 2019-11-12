#pragma once
struct Mix_Chunk;
#include <SDL_mixer.h>
#include <unordered_map>
#include <string>
namespace Engine {
	typedef std::unordered_map<std::string, Mix_Chunk*> SoundEffects;
	class SoundManager
	{
	public:
		static void PlaySoundEffect(std::string soundName, int loops, int volume);
		static void SetMusic(const char* _path, int volume);
		static bool AddSoundEffect(const std::string& name, const char* _path);
		static bool HasSoundEffect(const std::string& name);
	private:
		static Mix_Music* music;
		static SoundEffects soundeffects;
	};
}

