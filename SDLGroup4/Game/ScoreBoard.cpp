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

	backToMenuButton = new Engine::Button({ 350, 80, 550, 750 }, { 0, 255, 0, 255 });
	backToMenuText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 45, "BACK TO MENU", { 255, 255, 255, 255 }, { 45, 45, 25, 15 });
	backToMenuButton->SetOnClickEvent(OnClickMenuButton);

	std::vector<Engine::GameElement*> scoreTexts;
	Engine::UIManager::AddObjectsToCanvas(4, { topTenScoreListTitle, backToMenuButton });

	float textPosY = 200;
	int index = 1;
	
	for (auto score : scoreRecorder->GetSavedRecords())
	{
		if (index > 10)
			break;

		scoreTexts.push_back(new Engine::Text("Assets/Fonts/Roboto-Medium.ttf", 30,
			std::to_string(index) + "     " + score->Date + "  |   " + std::to_string(score->Score), 
			{ 255, 255, 255, 255 }, { 50, 50, (index > 9 ? 483.f : 500.f), textPosY }));

		textPosY += 50;
		index++;
	}
		
	Engine::UIManager::AddObjectsToCanvas(4, scoreTexts);

	backToMenuButton->SetText(backToMenuText);
	AddClickables();
}

void ScoreBoard::Start()
{
	Engine::UIManager::CleanElement(4);
	Engine::Scene::Start();
	SetUpUI();
	AddClickables();
}

void OnClickMenuButton()
{
	ScoreBoard::ThisScene->LoadScene(0);
}



