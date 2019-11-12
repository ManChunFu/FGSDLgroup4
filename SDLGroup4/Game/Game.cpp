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
#include <UIManager.h>
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
	Engine::UIManager::Initialize();

#pragma region MainMenu Implementation
	Engine::Text* StartMenuTitle = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 50, "WIZARDLAND", { 255, 255, 255, 255 }, { 50, 50, 300, 100 });
	PlayButton = new Engine::Button({ 200, 80, 350, 200 }, { 0, 255, 0, 255 });
	Engine::Text* PlayText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "PLAY", { 255, 255, 255, 255 }, { 45, 45, 0, 0 });
	PlayButton->SetText(PlayText);
	PlayButton->SetOnClickEvent(OnClickMyButton);
	Engine::Text* QuitText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "QUIT", { 255, 255, 255, 255 }, { 45, 45, 395, 350 });
	Engine::Text* RecordTextOnButton = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "SCORE RECORDS", { 255, 255, 255, 255 }, { 45, 45, 280, 450 });


	Engine::UIManager::AddObjectsToScene(0, { StartMenuTitle, PlayButton, QuitText, RecordTextOnButton });
	inputManager->AddClickableElement(PlayButton);

#pragma endregion MainMenu Implementation

	SoundManager::AddSoundEffect("Bell", "Assets/Sounds/bell.wav");
	Engine::SoundManager::SetMusic("Assets/Sounds/Rain.wav", 20);
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
		Engine::Time::StartFrame();
		frameStartTick = SDL_GetTicks();
		Update();
		HandleEvents();
		Render();
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
	Engine::SoundManager::Shutdown();
	Engine::UIManager::Shutdown();
	Engine::CollisionManager::Shutdown();
	EntityManager::Shutdown();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	Mix_CloseAudio();
}
void Engine::Application::HandleEvents()
{
	Engine::CollisionManager::Update();
}

void Engine::Application::Update()
{
	inputManager->Update(isRunning);
	Engine::UIManager::Update();
	Engine::EntityManager::Update();
}

void Engine::Application::Render()
{
	Engine::Window::RenderClear();
	Engine::UIManager::Render();
	SDL_SetRenderDrawColor(Engine::Window::Renderer, 0, 0, 0, 255);//background color
	Engine::EntityManager::Render();
	Engine::Window::RenderPresent(); 
}

void OnClickMyButton()
{
	Engine::Text* PlayText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "PLAYING", { 255, 0, 0, 255 }, { 45, 45, 650, 365 });
	PlayButton->SetText(PlayText);
	PlayText = nullptr;
}

