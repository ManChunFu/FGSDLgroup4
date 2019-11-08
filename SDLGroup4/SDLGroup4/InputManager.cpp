#include "InputManager.h"
#include <iostream>
namespace Engine {
	SDL_Event InputManager::event;
		
	InputManager::InputManager()
	{
		keys = SDL_GetKeyboardState(nullptr);
		lastKeys = keys;
	}

	void InputManager::Shutdown()
	{
		delete lastKeys;
		lastKeys = nullptr;
		delete keys;
		keys = nullptr;
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
		if (IsKeyDown(SDL_SCANCODE_ESCAPE)) { isRunning = false; }
	}
}