#pragma once
#include <Scene.h>
class MainMenu : public Engine::Scene
{
public:
	MainMenu(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) { SetUpUI(); }
	static MainMenu* mainmenu;
	void Shutdown() override;
private:
	virtual void SetUpUI() override;
	Engine::Text* startMenuTitle;
	Engine::Button* playButton;
	Engine::Text* playText;
	Engine::Button* quitButton;
	Engine::Text* quitText;
	Engine::Button* scoreButton;
	Engine::Text* scoreRecordText;
};
	void OnClickQuitButton();
	void OnClickPlayButton();
	void OnClickScoreButton();


