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
	enemy.push_back(new Enemy(1));
	enemy[enemy.size() - 1]->AddCollider("Enemy");
	enemy[enemy.size() - 1]->AddSprite("Enemy");
}

void MainScene::createPlayer()
{
	player = new Player(inputManager, 1);
	player->AddCollider("Player");
	player->AddSprite("Player");
}

void MainScene::SetUpUI()
{
}
