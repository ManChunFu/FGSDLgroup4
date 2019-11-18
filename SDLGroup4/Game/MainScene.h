#pragma once
#include <Scene.h>
#include <vector>
#include <TextureManager.h>

class Player;
class Enemy;
class MainScene : public Engine::Scene
{
public:
	MainScene(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) 
	{ 
		mainScene = this; 
		Engine::TextureManager::AddTexture("Enemy", "Assets/Sprites/enemy_drone_larger_red.png");
		Engine::TextureManager::AddTexture("Bullet", "Assets/Sprites/enemy_drone_larger_red.png");
		Engine::TextureManager::AddTexture("Player", "Assets/Sprites/Hopping_rabbit_dude.png");
		createPlayer(); 
		CreateEnemy(); 
	}

	static MainScene* mainScene;
	void Update() override;
private:
	void CreateEnemy();
	std::vector<Enemy*> enemy;

	Player* player;
	void createPlayer();
	
	// Inherited via Scene
	virtual void SetUpUI() override;
};

