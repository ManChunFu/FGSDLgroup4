#pragma once
#include <Scene.h>
#include <vector>
#include <TextureManager.h>
#include "Map.h"

class Player;
class Enemy;
class Map;

class MainScene : public Engine::Scene
{
public:
	MainScene(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) 
	{ 
		mainScene = this; 
		Engine::TextureManager::AddTexture("Enemy", "Assets/Sprites/enemy.png");
		Engine::TextureManager::AddTexture("EnemyRun", "Assets/Sprites/walk.png");
		Engine::TextureManager::AddTexture("FireSpell", "Assets/Sprites/FireSpell.png");
		Engine::TextureManager::AddTexture("Player", "Assets/Sprites/Hopping_rabbit_dude.png");
		Engine::TextureManager::AddTexture("Projectile1", "Assets/Sprites/laserX.png");
		Engine::TextureManager::AddTexture("Projectile2", "Assets/Sprites/laserY.png");
		Engine::TextureManager::AddTexture("Explosion", "Assets/2D Galaxy Assets/Game/Sprites/Explosion/Explosion_00019.png");
		Engine::TextureManager::AddTexture("Ground01", "Assets/Sprites/floor_sand_rock_0.png");
		Engine::TextureManager::AddTexture("Ground02", "Assets/Sprites/floor_sand_rock_1.png");
		Engine::TextureManager::AddTexture("Ground03", "Assets/Sprites/floor_sand_rock_2.png");
		Engine::TextureManager::AddTexture("Ground04", "Assets/Sprites/floor_sand_rock_3.png");
		CreateMap();
		CreatePlayer(); 
		CreateEnemy(); 
	}

	Map* map;
	Player* player;
	static MainScene* mainScene;
	void Update() override;
	void Render() override;
private:
	void CreateEnemy();
	std::vector<Enemy*> enemy;
	Engine::Vector2D RandomeStartPos();

	void CreatePlayer();

	//trying different techniques to create tilemap (um)
	void CreateMap();
	
	// Inherited via Scene
	virtual void SetUpUI() override;
};

