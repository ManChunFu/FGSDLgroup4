#pragma once
#include <Scene.h>
#include "ScoreRecorder.h"

class ScoreBoard : public Engine::Scene
{
public:
	ScoreBoard(Engine::Application* app, Engine::InputManager* input) : Scene(app, input)
	{
		Engine::UIManager::CreateCanvas();
		SetUpUI();
	};

	static ScoreBoard* ThisScene;
	void Shutdown() override;
	void AddClickables() override;
	void Start() override;

private:
	virtual void SetUpUI() override;
	Engine::Text* topTenScoreListTitle;
	Engine::Button* backToMenuButton;
	Engine::Text* backToMenuText;
	Engine::Text* scoreRecordList;

	ScoreRecorder* scoreRecorder;

};

void OnClickMenuButton();





