#pragma once
#include <Scene.h>
class MainMenu : public Engine::Scene
{
public:
	MainMenu(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) { SetUpUI(); }
	static MainMenu* mainMenu;
	void Shutdown() override;
	void AddClickables() override;
private:
	virtual void SetUpUI() override;
	void Start() override;
	Engine::Text* startMenuTitle;
	Engine::Button* playButton;
	Engine::Text* playText;
	Engine::Button* exitButton;
	Engine::Text* exitText;
	Engine::Button* scoreButton;
	Engine::Text* scoreRecordText;
};
namespace mainMenu {
	void OnClickExitButton();
	void OnClickPlayButton();
	void OnClickScoreButton();
}


