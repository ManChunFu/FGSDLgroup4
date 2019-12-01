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
	inputManager->AddClickableElement(menuButton);
}
void PauseMenu::Start()
{
	Init();
}
void PauseMenu::SetUpUI()
{
	Engine::UIManager::CreateCanvas({0,0,0,0}, { 0, 0, 250, 150 });
	playButton = new Engine::Button({ 200, 80, 345, 100 }, { 0, 255, 0, 255 });
	playText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "RESUME", { 255, 255, 255, 255 }, { 45, 45, 25, 15 });
	playButton->SetOnClickEvent(button::OnPlay);
	playButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	playButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };

	exitButton = new Engine::Button({ 200, 80, 345, 400 }, { 0, 255, 0, 255 });
	exitText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "EXIT", { 255, 255, 255, 255 }, { 45, 45, 58, 15 });
	exitButton->SetOnClickEvent(button::OnExit);
	exitButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	exitButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };
	
	
	menuButton = new Engine::Button({ 200, 80, 345, 250 }, { 0, 255, 0, 255 });
	menuText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "MENU", { 255, 255, 255, 255 }, { 45, 45, 50, 15 });
	menuButton->SetOnClickEvent(button::OnMenu);
	menuButton->ForegroundColor = new SDL_Color{ 255, 255, 255, 255 };
	menuButton->HoverForegroundColor = new SDL_Color{ 255, 0, 0, 255 };
	Engine::UIManager::AddObjectsToCanvas(3, { playButton, exitButton, menuButton });
	playButton->SetText(playText);
	exitButton->SetText(exitText);
	menuButton->SetText(menuText);
}

void button::OnPlay()
{
	Engine::Scene::ActiveScene->application->Pause = false;
	Engine::UIManager::ActiveCanvas = 1;
}

void button::OnExit()
{
	Engine::Scene::ActiveScene->application->isRunning = false;
}

void button::OnMenu()
{
	Engine::Scene::ActiveScene->application->Pause = false;
	Engine::Scene::ActiveScene->LoadScene(0);
}
