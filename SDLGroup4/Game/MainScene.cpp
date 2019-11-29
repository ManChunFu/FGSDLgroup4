#include "MainScene.h"
#include "Enemy.h"
#include "Player.h"
#include "Wizard.h"
#include "Map.h"
#include "Obstacle.h"
#include <SoundManager.h>
#include <GameTime.h>
#include "Tracker.h"
#include <Application.h>
MainScene* MainScene::mainScene = nullptr;
std::vector<Obstacle*> MainScene::obstacle;
void MainScene::Update()
{
	Scene::Update();
	spawner->Update();
	if (spawner->WizardSpawnRate > 30 && Tracker::Score > 2000) spawner->WizardSpawnRate = 25;
	std::string score = "SCORE: " + std::to_string(Tracker::Score);
	scoreText->Script(score);
	Enemy::hasPathFound = false;

}

void MainScene::Render()
{
	map->DrawMap();
	Scene::Render();
}


void MainScene::CreateMap()
{
	map = new Map();

}

void MainScene::Start()
{
	Engine::UIManager::ActiveCanvas = 1;
	Scene::Start();
	CreatePlayer();
	spawner->Reset();
	spawner->SpawnWizard();
	for (int i = 0; i < 1; i++)
	{ spawner->SpawnTroll(); }
	spawner->SpawnKnight();
	CreateMap();
	Engine::SoundManager::SetMusic("Assets/Sounds/BackgroundMusic.mp3", 20);
}

void MainScene::CreatePlayer()
{
	player = new Player(inputManager, 5);
	
	player->position.X = 500;
	player->position.Y = 500;
	//player->collider->solid = true;
}



void MainScene::SetUpUI()
{
}
