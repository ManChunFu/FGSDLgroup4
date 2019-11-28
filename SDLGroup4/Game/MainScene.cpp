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
void MainScene::Update()
{
	Scene::Update();
	spawner->Update();
	std::string score = "Score: " + std::to_string(Tracker::Score);
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
	CreateObstacle();
	CreatePlayer();
	for (int i = 0; i < 3; i++)
	{ spawner->SpawnTroll(); }
	CreateMap();
	Engine::SoundManager::SetMusic("Assets/Sounds/BackgroundMusic.mp3", 20);
}


void MainScene::CreateObstacle()
{
	lastPosition.X = 0;
	lastPosition.Y = 0;
	obstacle.push_back(new Obstacle());
	obstacle[obstacle.size() - 1]->AddCollider("Obstacle01", true);
	obstacle[obstacle.size() - 1]->AddSprite("Obstacle01");
	obstacle[0]->position = lastPosition;

	for (int row = 1; row < 5; row++)
	{
		obstacle.push_back(new Obstacle());
		obstacle[obstacle.size() - 1]->AddCollider("Obstacle01", true);
		obstacle[obstacle.size() - 1]->AddSprite("Obstacle01");
		obstacle[row]->position = ObstaclePlacement(lastPosition);
		lastPosition = obstacle[row]->position;
		/*obstacle->AddSprite("Obstacle01");
		obstacle->AddCollider("Obstacle01", true);
		obstacle->collider->solid = true;*/
	}
}

void MainScene::CreatePlayer()
{
	player = new Player(inputManager, 5);
	
	player->position.X = 500;
	player->position.Y = 500;
	//player->collider->solid = true;
}

Engine::Vector2D MainScene::ObstaclePlacement(Engine::Vector2D pos)
{
	Engine::Vector2D position;
	position.X = pos.X + 32;

	//use mandy's fanstatic logic for columns

	return position;
}

void MainScene::SetUpUI()
{
}
