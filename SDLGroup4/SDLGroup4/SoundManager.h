#pragma once
struct Mix_Chunk;
#include <SDL_mixer.h>
namespace Engine {
	class SoundManager
	{
	public:
		static void PlaySoundEffect(Mix_Chunk* sound);
		static Mix_Chunk* GetSound(const char* _path);
		static void SetMusic(const char* _path);
	private:
		static void PlayMusic();
		static Mix_Music* music;
	};
}

