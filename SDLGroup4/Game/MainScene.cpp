#include "MainScene.h"
#include "Enemy.h"

MainScene* MainScene::mainScene = nullptr;
void MainScene::Update()
{
	Scene::Update();
}

void MainScene::CreateEnemy()
{
	std::string path = "Assets/Sprites/enemy_drone_larger_red.png";
	enemy.push_back(new Enemy(1, path, 64, 64, 100.0f, 100.0f, mainScene));
}

void MainScene::createPlayer()
{
	std::string path = "Assets/Sprites/Hopping_rabbit_dude.png";
	player = new Player(inputManager, 1, path, 64, 24, 200.0f, 200.0f, mainScene);
}

void MainScene::SetUpUI()
{
}
