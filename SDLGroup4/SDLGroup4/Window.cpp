#include "Window.h"

#include <SDL_video.h>
#include <SDL_render.h>
#include <iostream>


SDL_Renderer* Engine::Window::Renderer = nullptr;

namespace Engine
{
	Window::Window(const std::string& _title, int _width, int _height) : title(_title), width(_width), height(_height) {}

	Window::~Window()
	{
		if (Renderer)
		{
			SDL_DestroyRenderer(Renderer);
			Renderer = nullptr;
		}

		if (window)
		{
			SDL_DestroyWindow(window);
			window = nullptr;
		}
	}


	bool Window::Init()
	{
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		if (window == nullptr)
		{
			std::cout << "Failed to create window. SDL Error: " << SDL_GetError << std::endl;
			return false;
		}

		Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (Renderer == nullptr)
		{
			std::cout << "Failed to create SDL_Rendeer. SDL Error: " << SDL_GetError << std::endl;
			return false;
		}

		return true;
	}
}