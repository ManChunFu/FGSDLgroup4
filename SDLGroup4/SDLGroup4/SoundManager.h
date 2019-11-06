#pragma once
struct Mix_Chunk;
#include <SDL_mixer.h>
namespace Engine {
	class SoundManager
	{
	public:
		static void PlaySoundEffect(Mix_Chunk* sound, int loops, int volume);
		static Mix_Chunk* GetSound(const char* _path);
		static void SetMusic(const char* _path, int volume);
	private:
		static Mix_Music* music;
	};
}

