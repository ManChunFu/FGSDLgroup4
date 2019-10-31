#pragma once

#include <string>
#include <SDL_events.h>

struct SDL_Window;
struct SDL_Renderer;

namespace Engine
{
	class Window
	{
	public:
		Window(const std::string& _title, int _width, int _height);
		~Window();

		static SDL_Renderer* Renderer;

		bool IsClosed() const { return closed; }
		void PollEvents(SDL_Event& event);

	private:
		std::string title;
		int width;
		int height;
		bool closed = false;

		SDL_Window* window = nullptr;

		bool init();

	};
}
