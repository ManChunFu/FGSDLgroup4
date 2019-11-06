#pragma once
struct Mix_Chunk;
namespace Engine {
	class SoundManager
	{
	public:
		static void PlaySoundEffect(Mix_Chunk* sound);
		static Mix_Chunk* GetSound(const char* _path);
	};
}

