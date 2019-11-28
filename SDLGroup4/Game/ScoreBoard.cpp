#include "ScoreBoard.h"
#include <InputManager.h>
#include "ScoreRecord.h"

ScoreBoard* ScoreBoard::ThisScene = nullptr;
void ScoreBoard::Shutdown()
{
	Scene::Shutdown();
	Engine::Text* topTenScoreListTitle = nullptr;
	Engine::Button* backToMenuButton = nullptr;
	Engine::Text* backToMenuText = nullptr;
	Engine::Text* scoreRecordList = nullptr;

	ScoreRecorder* scoreRecorder = nullptr;
}

void ScoreBoard::AddClickables()
{
	inputManager->AddClickableElement(backToMenuButton);
}

void ScoreBoard::SetUpUI()
{
	ThisScene = this;
	topTenScoreListTitle = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 50, "TOP 10 SCORES", { 0, 150, 200, 255 }, { 50, 50, 550, 100 });
	
	backToMenuButton = new Engine::Button({ 350, 80, 530, 800 }, { 0, 255, 0, 255 });
	backToMenuText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "BACK TO MENU", { 255, 255, 255, 255 }, { 45, 45, 40, 15 });
	backToMenuButton->SetOnClickEvent(OnClickMenuButton);
	
	std::vector<Engine::GameElement*> scoreTexts;
	Engine::UIManager::AddObjectsToCanvas(4, { topTenScoreListTitle, backToMenuButton});

	float textPosY = 200;
	//std::vector<ScoreRecord*> scores = scoreRecorder->GetSavedRecords();
	for (auto score : scoreRecorder->GetSavedRecords())
	{
		if (textPosY == 200)
		{
			scoreTexts.push_back(new Engine::Text("Assets/Fonts/Roboto-Medium.ttf", 50,
				score->Date + " | " + std::to_string(score->Score), { 255, 255, 255, 255 }, { 50, 50, 100, textPosY }));
		}
		else
			scoreTexts.push_back(new Engine::Text("Assets/Fonts/Roboto-Medium.ttf", 50,
				score->Date + " | " + std::to_string(score->Score), { 255, 255, 255, 255 }, { 50, 50, 100, textPosY}));

		textPosY += 100;
	}
	Engine::UIManager::AddObjectsToCanvas(4, scoreTexts);

	backToMenuButton->SetText(backToMenuText);
	AddClickables();
}

void ScoreBoard::Start()
{
	Engine::Scene::Start();
	AddClickables();
}

void OnClickMenuButton()
{

	ScoreBoard::ThisScene->LoadScene(0);
}



