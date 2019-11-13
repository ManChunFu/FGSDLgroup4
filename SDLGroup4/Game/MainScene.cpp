#include "MainScene.h"
#include "Enemy.h"
#include <string>
MainScene* MainScene::mainScene = nullptr;
void MainScene::Update()
{
	Scene::Update();
	/*CreateEnemy();*/
}

void MainScene::CreateEnemy()
{
	std::string path = "Assets/Sprites/enemy_drone_larger_red.png";
	enemy.push_back(new Enemy(1, path, 64, 64, 100.0f, 100.0f, mainScene));
}


void MainScene::createPlayer()
{
	std::string path = "Assets/Sprites/enemy_drone_larger_red.png";
	player = new Player(inputManager, 1, path, 64, 64, 200.0f, 200.0f, mainScene);
}

void MainScene::SetUpUI()
{
}
