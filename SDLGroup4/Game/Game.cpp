#include <InputManager.h>
#include <TextureManager.h>
#include <Animation.h>
#include <Time.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <Entity.h>
#include <SoundManager.h>
#include <SDL_mixer.h>
#include <UIManager.h>
#include <Text.h>
#include "Game.h"
#include <Scene.h>
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

#pragma region MainMenu Implementation

	startMenuTitle = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 50, "WIZARDLAND", { 0, 150, 150, 255 }, { 50, 50, 300, 20 });

	playButton = new Engine::Button({ 200, 80, 345, 150 }, { 0, 255, 0, 255 });
	playText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "PLAY", { 255, 255, 255, 255 }, { 45, 45, 55, 15 });
	playButton->SetOnClickEvent(OnClickPlayButton);
	playButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	playButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	quitButton = new Engine::Button({ 200, 80, 345, 300 }, { 0, 255, 0, 255 });
	quitText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "QUIT", { 255, 255, 255, 255 }, { 45, 45, 50, 15 });
	quitButton->SetOnClickEvent(OnClickQuitButton);
	quitButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	quitButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	scoreButton = new Engine::Button({ 400, 80, 250, 450 }, { 0, 255, 0, 255 });
	scoreRecordText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "SCORE RECORDS", { 255, 255, 255, 255 }, { 45, 45, 30, 15 });
	scoreButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	scoreButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };
	scoreButton->SetOnClickEvent(OnClickScoreButton);
	
	
	Engine::UIManager::AddObjectsToScene(0, { startMenuTitle, playButton, quitButton, scoreButton });
	playButton->SetText(playText);
	quitButton->SetText(quitText);
	scoreButton->SetText(scoreRecordText);
	inputManager->AddClickableElement(playButton);
	inputManager->AddClickableElement(quitButton);
	inputManager->AddClickableElement(scoreButton);

#pragma endregion MainMenu Implementation

	SoundManager::AddSoundEffect("Bell", "Assets/Sounds/bell.wav");
	Engine::SoundManager::SetMusic("Assets/Sounds/Rain.wav", 20);
	scenes.push_back(new Scene());
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
	if (activeScene > scenes.size()) activeScene = scenes.size();
	scenes[activeScene]->HandleEvents();
}

void Engine::Application::Update()
{
	inputManager->Update(isRunning);
	Engine::UIManager::Update();
	if (activeScene > scenes.size() - 1) activeScene = scenes.size() - 1;
	scenes[activeScene]->Update();
}

void Engine::Application::Render()
{
	Engine::Window::RenderClear();
	Engine::UIManager::Render();
	SDL_SetRenderDrawColor(Engine::Window::Renderer, 0, 0, 0, 255);//background color
	if (activeScene > scenes.size()) activeScene = scenes.size();
	scenes[activeScene]->Render();
	Engine::Window::RenderPresent(); 
}
void Engine::Application::LoadScene(int scene) 
{
	application->activeScene = scene;
}

void OnClickQuitButton()
{
	application->Quit();
}

void OnClickPlayButton()
{
	application->inputManager->ClearClickables();
	application->LoadScene(1);
	Engine::UIManager::ActiveCanvas = 1;
}
void OnClickScoreButton()
{

}

