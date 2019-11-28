#pragma once
#include <Scene.h>
#include "ScoreRecorder.h"

class GameOverScene : public Engine::Scene
{
public:
	GameOverScene(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) 
	{ 
		Engine::UIManager::CreateCanvas();
		SetUpUI(); 
	}
	static GameOverScene* thisScene;
	void Shutdown() override;
	void AddClickables() override;
	void Start() override;
private:
	virtual void SetUpUI() override;
	Engine::Text* ScoreText;
	Engine::Text* GameOverMenuTitle;
	Engine::Button* backToMenuButton;
	Engine::Text* backToMenuText;
	Engine::Button* exitButton;
	Engine::Text* exitText;
	Engine::Button* scoreButton;
	Engine::Text* scoreRecordText;
	ScoreRecorder* scoreRecorder;
};
namespace ButtonMethods
{
	void OnClickExitButton();
	void OnClickMenuButton();
	void OnClickScoreButton();

}