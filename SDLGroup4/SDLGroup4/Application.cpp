#include "Application.h"
#include "InputManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>


bool Engine::Application::Initialize()
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
	while (isRunning)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event) > 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
					isRunning = false;
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
		
		delete window;
		window = nullptr;
	}
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
void Engine::Application::HandleEvents()
{
	Engine::InputManager::Update();
	isRunning = Engine::InputManager::ProgramStatus();
}

void Engine::Application::Update()
{
}

void Engine::Application::Render()
{
	
}