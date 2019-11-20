#include <InputManager.h>
#include <GameTime.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <SoundManager.h>
#include <SDL_mixer.h>
#include <UIManager.h>
#include "MainMenu.h"
#include "Game.h"
#include <Scene.h>
#include "MainScene.h"
#include <TextureManager.h>
#pragma warning( push )
#pragma warning( disable : 4267)
//todo: add game over screen and on hover sounds to buttons
int main(int argc, char** argv)
{
	application = new Engine::Application();

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
	Engine::UIManager::Initialize();
	scenes.push_back(new MainMenu(this, inputManager));
	scenes.push_back(new MainScene(this, inputManager));
	SoundManager::AddSoundEffect("Bell", "Assets/Sounds/bell.wav");
	Engine::SoundManager::SetMusic("Assets/Sounds/Rain.wav", 20);
	Engine::Scene::ActiveScene = scenes[activeScene];
	return true;
}

void Engine::Application::Run()
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStartTick;
	int frameTime;
	while (isRunning)
	{
		Engine::GameTime::StartFrame();
		frameStartTick = SDL_GetTicks();
		Update();
		HandleEvents();
		Render();
		frameTime = SDL_GetTicks() - frameStartTick;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
		Engine::GameTime::EndFrame();
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
	Engine::SoundManager::Shutdown();
	Engine::TextureManager::Shutdown();
	Engine::UIManager::Shutdown();
	for (auto scene : scenes)
	{
		scene->Shutdown();
		delete scene;
	}
	scenes.clear();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	Mix_CloseAudio();
	
}


void Engine::Application::HandleEvents()
{
	if (!application->Pause)
	{
		if (activeScene > scenes.size()) activeScene = scenes.size();
		scenes[activeScene]->HandleEvents();
	}
}

void Engine::Application::Update()
{
	inputManager->Update(isRunning, application->Pause);
	Engine::UIManager::Update();
	if (!application->Pause)
	{
		if (activeScene > scenes.size() - 1) activeScene = scenes.size() - 1;
		scenes[activeScene]->Update();
	}

}

void Engine::Application::Render()
{
	Engine::Window::RenderClear();
	Engine::UIManager::Render();
	SDL_SetRenderDrawColor(Engine::Window::Renderer, 100, 100, 100, 255);//background color
	if (activeScene > scenes.size()) activeScene = scenes.size();
	scenes[activeScene]->Render();
	Engine::Window::RenderPresent(); 
}
void Engine::Application::LoadScene(int scene) 
{
	Engine::Scene::ActiveScene = scenes[scene];
	application->activeScene = scene;
}


#pragma warning( pop ) 