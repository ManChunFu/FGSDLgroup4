#include "MainMenu.h"
#include "Application.h"
#include <InputManager.h>
MainMenu* MainMenu::mainmenu;
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
	mainmenu = this;
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

}
void OnClickQuitButton()
{
	MainMenu::mainmenu->application->Quit();
}

void OnClickPlayButton()
{
	MainMenu::mainmenu->application->LoadScene(1);
	Engine::UIManager::ActiveCanvas = 1;
}
void OnClickScoreButton()
{

}
