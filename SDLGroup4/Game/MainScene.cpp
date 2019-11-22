#include "MainScene.h"
#include "Enemy.h"
#include "Player.h"
#include "Map.h"

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
	Scene::Start();
	CreatePlayer();
	CreateEnemy();
	CreateMap();
}

void MainScene::CreateEnemy()
{
	for (int i = 0; i < 5; i++)
	{
		enemy.push_back(new Enemy(1));
		enemy[enemy.size() - 1]->AddCollider("Enemy", true);
		enemy[enemy.size() - 1]->AddSprite("Enemy");
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

void MainScene::CreatePlayer()
{
	player = new Player(inputManager, 1);
	player->AddCollider("PlayerIdle", true);
	player->AddSprite("Player");
	player->position.X = 500;
	player->position.Y = 500;
	//player->collider->solid = true;
}

void MainScene::SetUpUI()
{
}
