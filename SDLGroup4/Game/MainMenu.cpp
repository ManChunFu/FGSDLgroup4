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
	Engine::Button* quitButton = nullptr;
	Engine::Text* quitText = nullptr;
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
	startMenuTitle = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 50, "BLINKER2XYX", { 0, 150, 150, 255 }, { 50, 50, 500, 80 });

	playButton = new Engine::Button({ 200, 80, 550, 250 }, { 0, 255, 0, 255 });
	playText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "PLAY", { 255, 255, 255, 255 }, { 45, 45, 55, 15 });
	playButton->SetOnClickEvent(mainmenu::OnClickPlayButton);
	playButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	playButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	exitButton = new Engine::Button({ 200, 80, 550, 400 }, { 0, 255, 0, 255 });
	exitText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "EXIT", { 255, 255, 255, 255 }, { 45, 45, 55, 15 });
	exitButton->SetOnClickEvent(mainmenu::OnClickExitButton);
	exitButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	exitButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	scoreButton = new Engine::Button({ 400, 80, 450, 550 }, { 0, 255, 0, 255 });
	scoreRecordText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "SCORE RECORDS", { 255, 255, 255, 255 }, { 45, 45, 30, 15 });
	scoreButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	scoreButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };
	scoreButton->SetOnClickEvent(mainmenu::OnClickScoreButton);
		
	Engine::UIManager::AddObjectsToCanvas(0, { startMenuTitle, playButton, exitButton, scoreButton });
	playButton->SetText(playText);
	exitButton->SetText(exitText);
	scoreButton->SetText(scoreRecordText);
	AddClickables();

}

void mainmenu::OnClickExitButton()
{
	MainMenu::mainMenu->application->Quit();
}

void mainmenu::OnClickPlayButton()
{
	MainMenu::mainMenu->LoadScene(1);
}
void mainmenu::OnClickScoreButton()
{
	MainMenu::mainMenu->LoadScene(2);
}
