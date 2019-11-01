#include "InputManager.h"
SDL_Event Engine::InputManager::event;

bool Engine::InputManager::ProgramStatus()
{
	switch (event.type)
	{
	case SDL_QUIT: return false; break;
	case SDL_KEYDOWN: if (event.key.keysym.sym == SDLK_ESCAPE) return false; break;
	default: break;
	}
	return true;
}