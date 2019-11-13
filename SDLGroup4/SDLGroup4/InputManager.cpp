#include "InputManager.h"
#include "Button.h"
#include <iostream>
#include <SDL_mouse.h>
#include "Text.h"

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

	void InputManager::Update(bool& isRunning, bool& pause)
	{
		lastKeys = keys;
		keys = SDL_GetKeyboardState(nullptr);
		while (SDL_PollEvent(&event)) 
		{
			if(event.type == SDL_QUIT)
			{ isRunning = false; return; }
			if (IsKeyDown(SDL_SCANCODE_ESCAPE)) { pause = !pause; return; }
			CheckMouseOnClickable();
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
	void InputManager::SetMouseCursor(SDL_SystemCursor newCursor)
	{
		SDL_Cursor* cursor;
		cursor = SDL_CreateSystemCursor(newCursor);
		SDL_SetCursor(cursor);
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
				if (gameElement->MouseCurrentStatus != MouseStatus::Hover)
				{
					gameElement->MouseCurrentStatus = MouseStatus::Hover;
					SetMouseCursor(SDL_SYSTEM_CURSOR_HAND); 
					if (gameElement->HoverForegroundColor != nullptr)
					{
						gameElement->OnHover();
					}
				}
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{ 
					gameElement->OnClick(); 
				}
				return;
			}
			else if (gameElement->MouseCurrentStatus != MouseStatus::None)
			{
				gameElement->MouseCurrentStatus = MouseStatus::None;
				SetMouseCursor(SDL_SYSTEM_CURSOR_ARROW);

				if (gameElement->ForegroundColor != nullptr)
				{
					gameElement->LeavingHover();
				}				
			}
		}
		SetMouseCursor(SDL_SYSTEM_CURSOR_ARROW);
	}
}