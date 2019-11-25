#include "PauseMenu.h"
#include <UIManager.h>
#include <Text.h>
#include <Button.h>
#include <InputManager.h>
#include <Application.h>
void PauseMenu::Init()
{

	inputManager->AddClickableElement(playButton);
	inputManager->AddClickableElement(exitButton);
}
void PauseMenu::Start()
{
	Init();
}
void PauseMenu::SetUpUI()
{
	Engine::UIManager::CreateCanvas({0,0,0,0}, { 0, 0, 250, 150 });
	playButton = new Engine::Button({ 200, 80, 345, 150 }, { 0, 255, 0, 255 });
	playText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "PLAY", { 255, 255, 255, 255 }, { 45, 45, 55, 15 });
	playButton->SetOnClickEvent(button::OnPlay);
	playButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	playButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	exitButton = new Engine::Button({ 200, 80, 345, 300 }, { 0, 255, 0, 255 });
	exitText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "EXIT", { 255, 255, 255, 255 }, { 45, 45, 55, 15 });
	exitButton->SetOnClickEvent(button::OnExit);
	exitButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	exitButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };
	Engine::UIManager::AddObjectsToCanvas(2, { playButton, exitButton });
	playButton->SetText(playText);
	exitButton->SetText(exitText);
	Init();
}

void button::OnPlay()
{
	Engine::Scene::ActiveScene->application->Pause = false;
	Engine::UIManager::ActiveCanvas = 5;
}

void button::OnExit()
{
	Engine::Scene::ActiveScene->application->isRunning = false;
}