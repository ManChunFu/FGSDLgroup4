#include "Application.h"

#include <SDL_events.h>
#include <SDL_error.h>
#include <iostream>

bool Engine::Application::Initialize()
{
	window = new Engine::Window("Main Window", 1440, 900);
	if (!window->Init())
	{
		std::cout << "Failed to initialize. SDL Error: " << SDL_GetError << std::endl;
		return false;
	}
	return true;
}

void Engine::Application::Run()
{
	while (!window->IsClosed())
	{
		SDL_Event event;
		while (SDL_PollEvent(&event) > 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				window->closed = true;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
					window->closed = true;
				break;
			default:
				break;
			}
		}
	}
}

void Engine::Application::Shutdown()
{
	if (window)
	{
		window->~Window();
		delete window;
		window = nullptr;
	}
}
