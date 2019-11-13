#pragma once
#include <Scene.h>
class MainMenu : public Engine::Scene
{
public:
	MainMenu(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) { SetUpUI(); }
	static MainMenu* mainMenu;
	void Shutdown() override;
private:
	virtual void SetUpUI() override;
	Engine::Text* startMenuTitle;
	Engine::Button* playButton;
	Engine::Text* playText;
	Engine::Button* exitButton;
	Engine::Text* exitText;
	Engine::Button* scoreButton;
	Engine::Text* scoreRecordText;
};
	void OnClickExitButton();
	void OnClickPlayButton();
	void OnClickScoreButton();


