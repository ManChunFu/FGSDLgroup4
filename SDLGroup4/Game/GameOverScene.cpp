#include "GameOverScene.h"
#include <InputManager.h>
#include <Application.h>
GameOverScene* GameOverScene::thisScene;
void GameOverScene::Shutdown()
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

void GameOverScene::AddClickables()
{
	inputManager->AddClickableElement(backToMenuButton);
	inputManager->AddClickableElement(exitButton);
	inputManager->AddClickableElement(scoreButton);
}

void GameOverScene::SetUpUI()
{
	thisScene = this;
	GameOverMenuTitle = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 50, "Game Over!", { 0, 150, 200, 255 }, { 50, 50, 300, 20 });
	Engine::UIManager::CreateCanvas();

	backToMenuButton = new Engine::Button({ 350, 80, 280, 150 }, { 0, 255, 0, 255 });
	backToMenuText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "Back To Menu", { 255, 255, 255, 255 }, { 45, 45, 40, 15 });
	backToMenuButton->SetOnClickEvent(ButtonMethods::OnClickMenuButton);
	backToMenuButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	backToMenuButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	exitButton = new Engine::Button({ 200, 80, 345, 300 }, { 0, 255, 0, 255 });
	exitText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "EXIT", { 255, 255, 255, 255 }, { 45, 45, 50, 15 });
	exitButton->SetOnClickEvent(ButtonMethods::OnClickExitButton);
	exitButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	exitButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	scoreButton = new Engine::Button({ 400, 80, 250, 450 }, { 0, 255, 0, 255 });
	scoreRecordText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "SCORE RECORDS", { 255, 255, 255, 255 }, { 45, 45, 30, 15 });
	scoreButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	scoreButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };
	scoreButton->SetOnClickEvent(ButtonMethods::OnClickScoreButton);
	Engine::UIManager::AddObjectsToCanvas(1, { GameOverMenuTitle, backToMenuButton, exitButton, scoreButton });
	backToMenuButton->SetText(backToMenuText);
	exitButton->SetText(exitText);
	scoreButton->SetText(scoreRecordText);
	AddClickables();
}

void ButtonMethods::OnClickExitButton()
{
	GameOverScene::thisScene->application->Quit();
}

void ButtonMethods::OnClickMenuButton()
{
	GameOverScene::thisScene->application->LoadScene(0);
	Engine::UIManager::ActiveCanvas = 0;
}
void ButtonMethods::OnClickScoreButton()
{
	GameOverScene::thisScene->application->LoadScene(0);
	Engine::UIManager::ActiveCanvas = 1;
}