#pragma once
#include <SDL_keycode.h>
#include <SDL_scancode.h>
#include <SDL_events.h>
#include <vector>
#include "GameElement.h"

namespace Engine
{
	class InputManager
	{
	public:
		InputManager();
		void Shutdown();
		void Update(bool& isRunning);
		bool IsKeyDown(SDL_Scancode key) const { return keys[key]; };
		std::vector<GameElement*> GameObjectsListener;

		void SetMouseCursor(SDL_SystemCursor newCursor);
	private:
		static SDL_Event event;
		const Uint8* keys = nullptr;
		const Uint8* lastKeys = nullptr;
		void CheckMouseOnClickable();
		SDL_SystemCursor mouseCursor = SDL_SYSTEM_CURSOR_ARROW;
	};
}