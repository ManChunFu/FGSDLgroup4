#include "InputManager.h"
#include "Button.h"
#include <iostream>
#include <SDL_mouse.h>

namespace Engine 
{
	SDL_Event InputManager::event;
		
	InputManager::InputManager()
	{
		keys = SDL_GetKeyboardState(nullptr);
		lastKeys = keys;
	}

	void InputManager::Shutdown()
	{
		for (auto gameElement : clickableObjects)
		{ if(gameElement) delete gameElement; }
		clickableObjects.clear();
		delete lastKeys;
		lastKeys = nullptr;
		delete keys;
		keys = nullptr;
	}

	void InputManager::Update(bool& isRunning)
	{
		lastKeys = keys;
		keys = SDL_GetKeyboardState(nullptr);
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type)
			{
			case SDL_QUIT: isRunning = false; return; break;
			}
			if (IsKeyDown(SDL_SCANCODE_ESCAPE)) { isRunning = false; return; }
			CheckMouseOnClickable();
		}

	}
	void InputManager::SetMouseCursor(SDL_SystemCursor newCursor)
	{
		SDL_Cursor* cursor;
		cursor = SDL_CreateSystemCursor(newCursor);
		SDL_SetCursor(cursor);
		mouseCursor = newCursor;
	}
	void InputManager::CheckMouseOnClickable()
	{
		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);

		for (auto gameElement : clickableObjects)
		{
			if (mouseX > gameElement->xCoordinate && mouseX < (gameElement->xCoordinate + gameElement->width) &&
				mouseY > gameElement->yCoordinate && mouseY < (gameElement->yCoordinate + gameElement->height))
			{
				if (mouseCursor != SDL_SYSTEM_CURSOR_HAND)
				{ SetMouseCursor(SDL_SYSTEM_CURSOR_HAND); }
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{ gameElement->OnClick(); }
				return;
			}
		}
		if (mouseCursor != SDL_SYSTEM_CURSOR_ARROW)
		{ SetMouseCursor(SDL_SYSTEM_CURSOR_ARROW); }
	}
}