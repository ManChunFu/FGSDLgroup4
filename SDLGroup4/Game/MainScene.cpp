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
	std::string path = "Assets/Sprites/enemy_drone_larger_red.png";
	enemy.push_back(new Enemy(1));
	enemy[enemy.size() - 1]->AddCollider("Enemy");
	enemy[enemy.size() - 1]->AddSprite(path);
}

void MainScene::createPlayer()
{
	std::string path = "Assets/Sprites/Hopping_rabbit_dude.png";
	player = new Player(inputManager, 1);
	player->AddCollider("Player");
	player->AddSprite(path);
}

void MainScene::SetUpUI()
{
}
