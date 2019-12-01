#include "GameOverScene.h"
#include <InputManager.h>
#include <Application.h>
#include "Tracker.h"

GameOverScene* GameOverScene::thisScene;
void GameOverScene::Shutdown()
{
	Scene::Shutdown();
}

void GameOverScene::AddClickables()
{
	inputManager->AddClickableElement(backToMenuButton);
	inputManager->AddClickableElement(exitButton);
	inputManager->AddClickableElement(scoreButton);
}

void GameOverScene::Start()
{
	Engine::Scene::Start();
	scoreRecorder->AddNewScore(Tracker::Score);
	std::string scoretext = "Your score: " + std::to_string(Tracker::Score);
	ScoreText->Script(scoretext);
	AddClickables();
}

void GameOverScene::SetUpUI()
{
	thisScene = this;
	gameOverBackground = new Engine::Image("GameOverBackground", { 1440, 900, 0, 0 });
	GameOverMenuTitle = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 100, "GAME OVER", { 0, 150, 150, 255 }, { 50, 50, 500, 120 });
	std::string scoretext = "YOUR SCORE : " + std::to_string(Tracker::Score);
	ScoreText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 60, scoretext, { 255, 255, 255, 255 }, { 45, 45, 540, 250 });

	backToMenuButton = new Engine::Button({ 350, 80, 580, 380 }, { 0, 255, 0, 255 });
	backToMenuText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "BACK TO MENU", { 255, 255, 255, 255 }, { 45, 45, 25, 15 });
	backToMenuButton->SetOnClickEvent(ButtonMethods::OnClickMenuButton);
	backToMenuButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	backToMenuButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	exitButton = new Engine::Button({ 200, 80, 650, 500 }, { 0, 255, 0, 255 });
	exitText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "EXIT", { 255, 255, 255, 255 }, { 45, 45, 58, 15 });
	exitButton->SetOnClickEvent(ButtonMethods::OnClickExitButton);
	exitButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	exitButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	scoreButton = new Engine::Button({ 400, 80, 560, 630 }, { 0, 255, 0, 255 });
	scoreRecordText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "SCORE RECORDS", { 255, 255, 255, 255 }, { 45, 45, 30, 15 });
	scoreButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	scoreButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };
	scoreButton->SetOnClickEvent(ButtonMethods::OnClickScoreButton);
	Engine::UIManager::AddObjectsToCanvas(2, { gameOverBackground, GameOverMenuTitle, backToMenuButton, exitButton, scoreButton, ScoreText });
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
	GameOverScene::thisScene->LoadScene(0);
}
void ButtonMethods::OnClickScoreButton()
{
	GameOverScene::thisScene->LoadScene(4);
}