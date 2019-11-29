#include "MainMenu.h"
#include <Application.h>
#include <InputManager.h>
#include <SoundManager.h>
#include "Tracker.h"
MainMenu* MainMenu::mainMenu = nullptr;
void MainMenu::Shutdown()
{
	Scene::Shutdown();
	Engine::Text* startMenuTitle = nullptr;
	Engine::Button* playButton = nullptr;
	Engine::Text* playText = nullptr;
	Engine::Button* exitButton = nullptr;
	Engine::Text* exitText = nullptr;
	Engine::Button* scoreButton = nullptr;
	Engine::Text* scoreRecordText = nullptr;
}
void MainMenu::AddClickables()
{
	inputManager->AddClickableElement(playButton);
	inputManager->AddClickableElement(exitButton);
	inputManager->AddClickableElement(scoreButton);
	Engine::SoundManager::SetMusic("Assets/Sounds/Menu.mp3", 20);
}
void MainMenu::SetUpUI()
{
	Tracker::Score = 0;
	Tracker::Enemies = 0;
	mainMenu = this;

	menuBackground = new Engine::Image("MenuBackground", { 1440, 900, 0, 0 });
	startMenuTitle = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 100, "BLINKER2XYX", { 0, 150, 150, 255 }, { 50, 50, 480, 120 });

	playButton = new Engine::Button({ 200, 80, 640, 300 }, { 0, 255, 0, 255 });
	playText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "PLAY", { 255, 255, 255, 255 }, { 45, 45, 55, 15 });
	playButton->SetOnClickEvent(mainMenu::OnClickPlayButton);
	playButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	playButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	exitButton = new Engine::Button({ 200, 80, 640, 450 }, { 0, 255, 0, 255 });
	exitText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "EXIT", { 255, 255, 255, 255 }, { 45, 45, 55, 15 });
	exitButton->SetOnClickEvent(mainMenu::OnClickExitButton);
	exitButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	exitButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	scoreButton = new Engine::Button({ 400, 80, 540, 600 }, { 0, 255, 0, 255 });
	scoreRecordText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "SCORE RECORDS", { 255, 255, 255, 255 }, { 45, 45, 30, 15 });
	scoreButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	scoreButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };
	scoreButton->SetOnClickEvent(mainMenu::OnClickScoreButton);
		
	Engine::UIManager::AddObjectsToCanvas(0, { menuBackground, startMenuTitle, playButton, exitButton, scoreButton });
	playButton->SetText(playText);
	exitButton->SetText(exitText);
	scoreButton->SetText(scoreRecordText);
	AddClickables();
}

void MainMenu::Start()
{
	Engine::Scene::Start();
	AddClickables();
}

void mainMenu::OnClickExitButton()
{
	MainMenu::mainMenu->application->Quit();
}

void mainMenu::OnClickPlayButton()
{
	MainMenu::mainMenu->LoadScene(1);
	Tracker::Score = 0;
}
void mainMenu::OnClickScoreButton()
{
	MainMenu::mainMenu->LoadScene(4);
}
