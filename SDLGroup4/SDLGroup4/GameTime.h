#pragma once
#include <SDL_stdinc.h>
namespace Engine {
	class GameTime {
	public:
		static float DeltaTime() { return deltaTime; }
		static void StartFrame();
		static void EndFrame();
	private:
		static Uint64 startTime;
		static Uint64 endTime;
		static float deltaTime;
	};
}