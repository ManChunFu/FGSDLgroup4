#pragma once

#include <string>

struct SDL_Window;
struct SDL_Renderer;

namespace Engine
{
	class Window
	{
	public:
		Window(const std::string& _title, int _width, int _height);
		~Window();

		bool Init();
		static SDL_Renderer* Renderer;

	private:
		std::string title;
		int width;
		int height;
		
		SDL_Window* window = nullptr;

	};
}
