#pragma once
#include <SDL_keycode.h>
#include <SDL_scancode.h>
#include <SDL_events.h>
#include <vector>
#include "IClickable.h"
#include <string>
enum Key { Q, W, E, R, T, Y, U, I, O, P, A, S, D, F, G, H, J, K, L, Z, X, C, V, B, N, M, RETURN, ESCAPE, BACKSPACE, LCTRL, RCTRL, LALT, RALT, SPACE };
namespace Engine
{
	class InputManager
	{
	public:
		InputManager();
		void Shutdown();
		void Update(bool& isRunning, bool& pause);
		bool IsKeyDown(SDL_Scancode key) const { return keys[key]; };
		void AddClickableElement(IClickable* element) { clickableObjects.push_back(element); }
		void ClearClickables() { clickableObjects.clear(); }
		void ClearClickables(bool all) 
		{
			for (auto gameElement : clickableObjects)
			{ if (gameElement) delete gameElement; }
			clickableObjects.clear();
		}
		bool IsKeyPressed(Key key);
		bool IsKeyReleased(Key key);
		int GetAxis(std::string Axis);
	private:
		bool IsKeyReleased(SDL_Scancode key) const;
		bool IsKeyPressed(SDL_Scancode key) const;
		void SetMouseCursor(SDL_SystemCursor newCursor);
		std::vector<IClickable*> clickableObjects;
		static SDL_Event event;
		const Uint8* keys = nullptr;
		Uint8 lastKeys[256];
		void CheckMouseOnClickable();
		SDL_SystemCursor mouseCursor = SDL_SYSTEM_CURSOR_ARROW;
	};
}