#include <InputManager.h>
#include <TextureManager.h>
#include <Animation.h>
#include <Time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <CollisionManager.h>
#include <EntityManager.h>
#include <Entity.h>
#include <SoundManager.h>
#include <SDL_mixer.h>
#include <Canvas.h>
#include <Text.h>
#include "Game.h"

int main(int argc, char** argv)
{
	Engine::Application* application = new Engine::Application();

	if (!application->Initialize())
	{
		application->Shutdown();
		delete application;
		application = nullptr;
	}

	application->Run();
	application->Shutdown();
	delete application;
	application = nullptr;

	return 0;
}

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
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		return false;
	}

	window = new Engine::Window("Main Window", 1440, 900);
	if (!window->Init())
	{
		std::cout << "Failed to initialize. SDL Error: " << SDL_GetError << std::endl;
		return false;
	}
	inputManager = new Engine::InputManager();

	return true;
}

void Engine::Application::Run()
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStartTick;
	int frameTime;
	Mix_Chunk* sound = SoundManager::GetSound("Assets/Sounds/bell.wav");
	Engine::SoundManager::SetMusic("Assets/Sounds/Rain.wav", 20);

	Engine::Canvas* StartMenuCanvas = new Engine::Canvas({ 0, 200, 200, 255 }, { 900, 600, 250, 150 });
	Engine::Text* StartMenuTitle = new Engine::Text("Assets/Fonts/Roboto-Medium.ttf", 50, "WIZARDLAND", { 255, 255, 255, 255 }, { 50, 50, 275, 50 });
	StartMenuCanvas->AddChild(StartMenuTitle);
	while (isRunning)
	{
		StartMenuCanvas->Render();

		Engine::Time::StartFrame();
		frameStartTick = SDL_GetTicks();
		Render();
		StartMenuCanvas->Render();
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
	Mix_CloseAudio();
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
	Engine::Window::RenderPresent();
	SDL_SetRenderDrawColor(Engine::Window::Renderer, 0, 0, 0, 255);//background color
	Engine::Window::RenderClear();
	Engine::EntityManager::Render();
	
}


