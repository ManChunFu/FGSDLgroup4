#pragma once
#include <Scene.h>
class GameOverScene : public Engine::Scene
{
public:
	GameOverScene(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) { SetUpUI(); }
	static GameOverScene* thisScene;
	void Shutdown() override;
	void AddClickables() override;
private:
	virtual void SetUpUI() override;
	Engine::Text* GameOverMenuTitle;
	Engine::Button* backToMenuButton;
	Engine::Text* backToMenuText;
	Engine::Button* exitButton;
	Engine::Text* exitText;
	Engine::Button* scoreButton;
	Engine::Text* scoreRecordText;
};
namespace ButtonMethods
{
	void OnClickExitButton();
	void OnClickMenuButton();
	void OnClickScoreButton();

}