#include "MainScene.h"
#include "Enemy.h"
#include "Player.h"
#include "Map.h"
#include "Obstacle.h"
#include <SoundManager.h>
MainScene* MainScene::mainScene = nullptr;
void MainScene::Update()
{
	Scene::Update();
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
	Engine::UIManager::ActiveCanvas = 10;
	Scene::Start();
	CreateObstacle();
	CreatePlayer();
	CreateEnemy();
	CreateMap();
	Engine::SoundManager::SetMusic("Assets/Sounds/BackgroundMusic.mp3", 20);
}

void MainScene::CreateEnemy()
{
	for (int i = 0; i < 1; i++)
	{
		enemy.push_back(new Enemy(5));
		Engine::Vector2D randomPos = RandomeStartPos();
		enemy[i]->position = randomPos;
	}
}

Engine::Vector2D MainScene::RandomeStartPos()
{
	float x = rand() % 800 + 100;
	float y = rand() % 450 + 100;

	Engine::Vector2D position;
	position.X = x;
	position.Y = y;
	return position;
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
	player = new Player(inputManager, 100);
	
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
