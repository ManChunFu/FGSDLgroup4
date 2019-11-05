#include "Time.h"
#include <SDL_timer.h>
namespace Engine {
	Uint64 Time::startTime;
	Uint64 Time::endTime;
	float Time::deltaTime;
	void Time::StartFrame()
	{
		startTime = SDL_GetPerformanceCounter();
	}
	void Time::EndFrame()
	{
		endTime = SDL_GetPerformanceCounter();
		deltaTime = (endTime - startTime) / (float)SDL_GetPerformanceFrequency();
	}
}