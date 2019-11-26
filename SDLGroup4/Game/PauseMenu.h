#pragma once
#include <Scene.h>
class PauseMenu : public Engine::Scene
{
public:
	PauseMenu(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) { SetUpUI(); }
	void Init();
	void Start() override;
private:
	Engine::Button* playButton;
	Engine::Text* playText;
	Engine::Button* exitButton;
	Engine::Text* exitText;
	Engine::Button* menuButton;
	Engine::Text* menuText;
	
	// Inherited via Scene
	virtual void SetUpUI() override;
};

namespace button
{
	void OnPlay();
	void OnExit();
	void OnMenu();
}