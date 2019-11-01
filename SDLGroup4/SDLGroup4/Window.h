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

		bool closed = false;
		static SDL_Renderer* Renderer;

		bool Init();
		bool IsClosed() const { return closed; }

	private:
		std::string title;
		int width;
		int height;
		
		SDL_Window* window = nullptr;

	};
}
