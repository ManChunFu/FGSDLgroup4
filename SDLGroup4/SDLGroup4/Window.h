#pragma once

#include <string>
#include <SDL.h>
struct SDL_Window;

namespace Engine
{
	class Window
	{
	public:
		Window(const std::string& _title, int _width, int _height);
		~Window();

		bool Init();
		static SDL_Renderer* Renderer;
		static void RenderClear() { SDL_RenderClear(Renderer); }
		static void RenderPresent() { SDL_RenderPresent(Renderer); }
		int ScreenWidth() { return width; }
		int ScreenHeight() { return height; }
	private:
		std::string title;
		int width;
		int height;
		
		SDL_Window* window = nullptr;

	};
}
