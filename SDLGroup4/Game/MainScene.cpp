#include "MainScene.h"
#include "Enemy.h"
#include "Player.h"
#include <InputManager.h>
MainScene* MainScene::mainScene = nullptr;
void MainScene::Update()
{
	Scene::Update();
}

void MainScene::CreateEnemy()
{
	for (int i = 0; i < 1; i++)
	{
		enemy.push_back(new Enemy(1));
		enemy[enemy.size() - 1]->AddCollider("Enemy");
		enemy[enemy.size() - 1]->AddSprite("Enemy");
		Engine::Vector2D randomPos = RandomeStartPos();
		enemy[i]->position = randomPos;
		enemy[i]->collider->solid = true;
	}
}

Engine::Vector2D MainScene::RandomeStartPos()
{
	float x = rand() % 800 + 1;
	float y = rand() % 450 + 1;

	Engine::Vector2D position;
	position.X = x;
	position.Y = y;
	return position;
}

void MainScene::createPlayer()
{
	player = new Player(inputManager, 1);
	player->AddCollider("Player");
	player->AddSprite("Player");
	player->position.X = 500;
	player->position.Y = 500;
	player->collider->solid = true;
}

void MainScene::SetUpUI()
{
}
