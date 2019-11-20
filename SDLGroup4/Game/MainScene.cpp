#include "MainScene.h"
#include "Enemy.h"
#include "Player.h"

MainScene* MainScene::mainScene = nullptr;
void MainScene::Update()
{
	Scene::Update();
}

void MainScene::CreateEnemy()
{
	for (int i = 0; i < 10; i++)
	{
		enemy.push_back(new Enemy(1));
		enemy[enemy.size() - 1]->AddCollider("Enemy");
		enemy[enemy.size() - 1]->AddSprite("Enemy");
		enemy[i]->position.X = i * 50;
		enemy[i]->position.Y = i * 50;
		enemy[i]->collider->solid = true;
	}
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
