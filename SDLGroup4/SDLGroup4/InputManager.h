#pragma once
#include <SDL.h>
namespace Engine
{
	class InputManager
	{
	public:
		static void Update() { SDL_PollEvent(&event); };
		static bool ProgramStatus();
	private:
		static SDL_Event event;
	};
}