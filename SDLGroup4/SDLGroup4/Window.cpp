#include "Window.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

SDL_Renderer* Engine::Window::Renderer = nullptr;

namespace Engine
{
	Window::Window(const std::string& _title, int _width, int _height) : title(_title), width(_width), height(_height)
	{
		closed = !init();
	}

	Window::~Window()
	{
		SDL_DestroyRenderer(Renderer);
		Renderer = nullptr;
		SDL_DestroyWindow(window);
		window = nullptr;
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}

	void Window::PollEvents(SDL_Event& event)
	{
		switch (event.type)
		{
		case SDL_QUIT:
			closed = true;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				closed = true;
			break;
		}
	}


	bool Window::init()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cout << "Failed to inialize SDL. SDL Error: " << SDL_GetError << std::endl;
			return false;
		}

		if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
		{
			std::cout << "Failed to inialize SDL_Image. SDL Error: " << SDL_GetError << std::endl;
			return false;
		}

		if (TTF_Init() == -1)
		{
			std::cout << "Failed to inialize SDL_ttf. SDL Error: " << SDL_GetError << std::endl;
			return false;
		}

		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		if (window == nullptr)
		{
			std::cout << "Failed to create window. SDL Error: " << SDL_GetError << std::endl;
			return false;
		}

		Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (Renderer == nullptr)
		{
			std::cout << "Failed to create SDL_Rendeer. SDL Error: " << SDL_GetError << std::endl;
			return false;
		}

		return true;
	}
}