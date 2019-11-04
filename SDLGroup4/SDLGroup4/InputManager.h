#pragma once
#include <SDL_keycode.h>
#include <SDL_scancode.h>
#include <SDL_events.h>
namespace Engine
{
	class InputManager
	{
	public:
		InputManager();
		void Update(bool& isRunning);
		bool IsKeyPressed(SDL_Scancode key) const;
		bool IsKeyReleased(SDL_Scancode key) const;
	private:
		static SDL_Event event;
		const Uint8* keys = nullptr;
		const Uint8* lastKeys = nullptr;
	};
}