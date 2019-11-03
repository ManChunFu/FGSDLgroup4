#include "Application.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "Animation.h"

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

	window = new Engine::Window("Main Window", 800, 600);
	if (!window->Init())
	{
		std::cout << "Failed to initialize. SDL Error: " << SDL_GetError << std::endl;
		return false;
	}


	return true;
}

void Engine::Application::Run()
{
	//texting animation
	Engine::Animation::AnimationSetup("Assets/Sprites/male_walk_anim.png", 3, 4, 200, 200);
	while (isRunning)
	{
		Render();
		HandleEvents();
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
	//testing animation
	Engine::Animation::PlayAnimation(4);


}