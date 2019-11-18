#include "MainMenu.h"
#include <Application.h>
#include <InputManager.h>

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
void MainMenu::SetUpUI()
{
	mainMenu = this;
	startMenuTitle = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 50, "WIZARDLAND", { 0, 150, 150, 255 }, { 50, 50, 300, 20 });

	playButton = new Engine::Button({ 200, 80, 345, 150 }, { 0, 255, 0, 255 });
	playText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "PLAY", { 255, 255, 255, 255 }, { 45, 45, 55, 15 });
	playButton->SetOnClickEvent(OnClickPlayButton);
	playButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	playButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	exitButton = new Engine::Button({ 200, 80, 345, 300 }, { 0, 255, 0, 255 });
	exitText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "EXIT", { 255, 255, 255, 255 }, { 45, 45, 50, 15 });
	exitButton->SetOnClickEvent(OnClickExitButton);
	exitButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	exitButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	scoreButton = new Engine::Button({ 400, 80, 250, 450 }, { 0, 255, 0, 255 });
	scoreRecordText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "SCORE RECORDS", { 255, 255, 255, 255 }, { 45, 45, 30, 15 });
	scoreButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	scoreButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };
	scoreButton->SetOnClickEvent(OnClickScoreButton);
		
	Engine::UIManager::AddObjectsToCanvas(0, { startMenuTitle, playButton, exitButton, scoreButton });
	playButton->SetText(playText);
	exitButton->SetText(exitText);
	scoreButton->SetText(scoreRecordText);
	inputManager->AddClickableElement(playButton);
	inputManager->AddClickableElement(exitButton);
	inputManager->AddClickableElement(scoreButton);

}

void OnClickExitButton()
{
	MainMenu::mainMenu->application->Quit();
}

void OnClickPlayButton()
{
	MainMenu::mainMenu->application->LoadScene(1);
	Engine::UIManager::ActiveCanvas = 1;
}
void OnClickScoreButton()
{

}
