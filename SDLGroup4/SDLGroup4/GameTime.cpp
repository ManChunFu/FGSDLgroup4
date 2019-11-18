#include "GameTime.h"
#include <SDL_timer.h>
namespace Engine {

	Uint64 GameTime::startTime;
	Uint64 GameTime::endTime;
	float GameTime::deltaTime;
	void GameTime::StartFrame()
	{
		startTime = SDL_GetPerformanceCounter();
	}
	void GameTime::EndFrame()
	{
		endTime = SDL_GetPerformanceCounter();
		deltaTime = (endTime - startTime) / (float)SDL_GetPerformanceFrequency();
	}
}
