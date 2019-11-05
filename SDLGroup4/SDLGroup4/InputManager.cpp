#include "InputManager.h"
#include <iostream>
namespace Engine {
	SDL_Event InputManager::event;
		
	InputManager::InputManager()
	{
		keys = SDL_GetKeyboardState(nullptr);
		lastKeys = keys;
	}

	void InputManager::Update(bool& isRunning)
	{
		lastKeys = keys;
		keys = SDL_GetKeyboardState(nullptr);
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT: isRunning = false; break;
		}
		if (IsKeyPressed(SDL_SCANCODE_ESCAPE)) {
			isRunning = false;
		}
	}

	bool InputManager::IsKeyPressed(SDL_Scancode key) const
	{
		if (!lastKeys[key] && keys[key]) { return true; }
		return false;
	}
	bool InputManager::IsKeyReleased(SDL_Scancode key) const
	{
		if (lastKeys[key] && !keys[key]) { return true; }
		return false;
	}
}