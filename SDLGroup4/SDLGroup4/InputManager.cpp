#include "InputManager.h"
#include "Button.h"
#include <iostream>
#include <SDL_mouse.h>
#include "Text.h"
#include <algorithm>
namespace Engine 
{
	SDL_Event InputManager::event;
		
	InputManager::InputManager()
	{
		keys = SDL_GetKeyboardState(nullptr);
		std::copy(keys, keys + 256, lastKeys);
	}

	void InputManager::Shutdown()
	{
		for (auto gameElement : clickableObjects)
		{ if(gameElement) delete gameElement; }
		clickableObjects.clear();
		delete keys;
		keys = nullptr;
	}

	void InputManager::Update(bool& isRunning, bool& pause)
	{
		std::copy(keys, keys + 256, lastKeys);
		keys = SDL_GetKeyboardState(nullptr);
		while (SDL_PollEvent(&event)) 
		{
			if(event.type == SDL_QUIT)
			{ isRunning = false; return; }
			CheckMouseOnClickable();
		}
	}
	bool InputManager::IsKeyPressed(Key key)
	{
		switch (key)
		{
		case Q: return IsKeyPressed(SDL_SCANCODE_Q); break;
		case W: return IsKeyPressed(SDL_SCANCODE_W); break;
		case E:return IsKeyPressed(SDL_SCANCODE_E); break;
		case R:return IsKeyPressed(SDL_SCANCODE_R); break;
		case T: return IsKeyPressed(SDL_SCANCODE_T); break;
		case Y:return IsKeyPressed(SDL_SCANCODE_Y); break;
		case U:return IsKeyPressed(SDL_SCANCODE_U); break;
		case I:return IsKeyPressed(SDL_SCANCODE_I); break;
		case O:return IsKeyPressed(SDL_SCANCODE_O); break;
		case P:return IsKeyPressed(SDL_SCANCODE_P); break;
		case A:return IsKeyPressed(SDL_SCANCODE_A); break;
		case S:return IsKeyPressed(SDL_SCANCODE_S); break;
		case D:return IsKeyPressed(SDL_SCANCODE_D); break;
		case F:return IsKeyPressed(SDL_SCANCODE_F); break;
		case G:return IsKeyPressed(SDL_SCANCODE_G); break;
		case H:return IsKeyPressed(SDL_SCANCODE_H); break;
		case J:return IsKeyPressed(SDL_SCANCODE_J); break;
		case K:return IsKeyPressed(SDL_SCANCODE_K); break;
		case L:return IsKeyPressed(SDL_SCANCODE_L); break;
		case Z:return IsKeyPressed(SDL_SCANCODE_Z); break;
		case X:return IsKeyPressed(SDL_SCANCODE_X); break;
		case C:return IsKeyPressed(SDL_SCANCODE_C); break;
		case V:return IsKeyPressed(SDL_SCANCODE_V); break;
		case B:return IsKeyPressed(SDL_SCANCODE_B); break;
		case N:return IsKeyPressed(SDL_SCANCODE_N); break;
		case M:return IsKeyPressed(SDL_SCANCODE_M); break;
		case RETURN:return IsKeyPressed(SDL_SCANCODE_RETURN); break;
		case ESCAPE:return IsKeyPressed(SDL_SCANCODE_ESCAPE); break;
		case BACKSPACE:return IsKeyPressed(SDL_SCANCODE_BACKSPACE); break;
		case LCTRL:return IsKeyPressed(SDL_SCANCODE_LCTRL); break;
		case RCTRL:return IsKeyPressed(SDL_SCANCODE_RCTRL); break;
		case LALT:return IsKeyPressed(SDL_SCANCODE_LALT); break;
		case RALT:return IsKeyPressed(SDL_SCANCODE_RALT); break;
		case SPACE:return IsKeyPressed(SDL_SCANCODE_SPACE); break;
		default:
			break;
		}
		return false;
	}
	bool InputManager::IsKeyReleased(Key key)
	{
		switch (key)
		{
		case Q: return IsKeyReleased(SDL_SCANCODE_Q); break;
		case W: return IsKeyReleased(SDL_SCANCODE_W); break;
		case E:return IsKeyReleased(SDL_SCANCODE_E); break;
		case R:return IsKeyReleased(SDL_SCANCODE_R); break;
		case T: return IsKeyReleased(SDL_SCANCODE_T); break;
		case Y:return IsKeyReleased(SDL_SCANCODE_Y); break;
		case U:return IsKeyReleased(SDL_SCANCODE_U); break;
		case I:return IsKeyReleased(SDL_SCANCODE_I); break;
		case O:return IsKeyReleased(SDL_SCANCODE_O); break;
		case P:return IsKeyReleased(SDL_SCANCODE_P); break;
		case A:return IsKeyReleased(SDL_SCANCODE_A); break;
		case S:return IsKeyReleased(SDL_SCANCODE_S); break;
		case D:return IsKeyReleased(SDL_SCANCODE_D); break;
		case F:return IsKeyReleased(SDL_SCANCODE_F); break;
		case G:return IsKeyReleased(SDL_SCANCODE_G); break;
		case H:return IsKeyReleased(SDL_SCANCODE_H); break;
		case J:return IsKeyReleased(SDL_SCANCODE_J); break;
		case K:return IsKeyReleased(SDL_SCANCODE_K); break;
		case L:return IsKeyReleased(SDL_SCANCODE_L); break;
		case Z:return IsKeyReleased(SDL_SCANCODE_Z); break;
		case X:return IsKeyReleased(SDL_SCANCODE_X); break;
		case C:return IsKeyReleased(SDL_SCANCODE_C); break;
		case V:return IsKeyReleased(SDL_SCANCODE_V); break;
		case B:return IsKeyReleased(SDL_SCANCODE_B); break;
		case N:return IsKeyReleased(SDL_SCANCODE_N); break;
		case M:return IsKeyReleased(SDL_SCANCODE_M); break;
		case RETURN:return IsKeyReleased(SDL_SCANCODE_RETURN); break;
		case ESCAPE:return IsKeyReleased(SDL_SCANCODE_ESCAPE); break;
		case BACKSPACE:return IsKeyReleased(SDL_SCANCODE_BACKSPACE); break;
		case LCTRL:return IsKeyReleased(SDL_SCANCODE_LCTRL); break;
		case RCTRL:return IsKeyReleased(SDL_SCANCODE_RCTRL); break;
		case LALT:return IsKeyReleased(SDL_SCANCODE_LALT); break;
		case RALT:return IsKeyReleased(SDL_SCANCODE_RALT); break;
		case SPACE:return IsKeyReleased(SDL_SCANCODE_SPACE); break;
		default:
			break;
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
	int InputManager::GetAxis(std::string Axis)
	{
		if (Axis == "Horizontal") 
		{
			if (IsKeyDown(SDL_SCANCODE_D) || IsKeyDown(SDL_SCANCODE_RIGHT))  { return 1; }
			if (IsKeyDown(SDL_SCANCODE_A) || IsKeyDown(SDL_SCANCODE_LEFT)) { return -1; }
		}
		if(Axis == "Vertical")
		{
			if (IsKeyDown(SDL_SCANCODE_S) || IsKeyDown(SDL_SCANCODE_DOWN)) { return 1; }
			if (IsKeyDown(SDL_SCANCODE_W) || IsKeyDown(SDL_SCANCODE_UP)) { return -1; }
		}
		if (Axis == "Space") if (IsKeyDown(SDL_SCANCODE_SPACE)) return 1;
		if (Axis == "Fire") if (IsKeyDown(SDL_SCANCODE_RETURN)) return 1;
		if (Axis == "Fire2") if (IsKeyDown(SDL_SCANCODE_LSHIFT)) return 1;
		

		return 0;
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