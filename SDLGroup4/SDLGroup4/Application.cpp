#include "Application.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "Animation.h"
#include "Time.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "CollisionManager.h"
#include "EntityManager.h"
#include "Entity.h"
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
	inputManager = new Engine::InputManager();
	entity = new Entity("Assets/Sprites/enemy_drone_larger_red.png", 100, 100, 100,100);
	return true;
}

void Engine::Application::Run()
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStartTick;
	int frameTime;
	//testing animation
	//Engine::Animation::AnimationSetup("Assets/Sprites/Attack1.png", 4, 1, 0, 0);
	
	while (isRunning)
	{
		Engine::Time::StartFrame();
		frameStartTick = SDL_GetTicks();
		Render();
		Update();
		HandleEvents();
		frameTime = SDL_GetTicks() - frameStartTick;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
		Engine::Time::EndFrame();
	}
}

void Engine::Application::Shutdown()
{
	if (inputManager) {
		delete inputManager;
		inputManager = nullptr;
	}
	if (window)
	{
		
		delete window;
		window = nullptr;
	}
	EntityManager::Shutdown();
	Engine::CollisionManager::Shutdown();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
void Engine::Application::HandleEvents()
{
	inputManager->Update(isRunning);
	Engine::CollisionManager::Update();
}

void Engine::Application::Update()
{
	Engine::EntityManager::Update();
}

void Engine::Application::Render()
{
	//testing animation
	Engine::Window::RenderClear();
	//Engine::Animation::PlayAnimation(4);
	
	Engine::EntityManager::Render();
	Engine::Window::RenderPresent();


}