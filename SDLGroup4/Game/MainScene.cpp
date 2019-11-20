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
	enemy.push_back(new Enemy(1));
	enemy[enemy.size() - 1]->AddCollider("Enemy");
	enemy[enemy.size() - 1]->AddSprite("Enemy");
	enemy[0]->position.X = 200;
	enemy[0]->position.Y = 200;
	enemy[0]->collider->solid = true;
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
