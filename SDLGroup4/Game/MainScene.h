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
		
		Engine::TextureManager::AddTexture("Enemy", "Assets/Sprites/Enemy/sprite.png");
		Engine::TextureManager::AddTexture("EnemyIdle", "Assets/Sprites/Enemy/IDLE1.png");
		Engine::TextureManager::AddTexture("EnemyWalk", "Assets/Sprites/Enemy/WALK.png");
		Engine::TextureManager::AddTexture("EnemyRun", "Assets/Sprites/Enemy/RUN.png");
		Engine::TextureManager::AddTexture("FireSpell", "Assets/Sprites/FireSpell.png");
		Engine::TextureManager::AddTexture("Player", "Assets/Sprites/Player/sprite.png");
		Engine::TextureManager::AddTexture("PlayerIdle", "Assets/Sprites/Player/IDLE.png");
		Engine::TextureManager::AddTexture("PlayerRun", "Assets/Sprites/Player/RUN.png");
		Engine::TextureManager::AddTexture("PlayerAttack", "Assets/Sprites/Player/ATTACK.png");
		Engine::TextureManager::AddTexture("IceBallSprite", "Assets/Sprites/Player/ICEBALLSprite.png");
		Engine::TextureManager::AddTexture("IceBall", "Assets/Sprites/Player/ICEBALL1.png");
		Engine::TextureManager::AddTexture("FireBall", "Assets/Sprites/player/FIREBALL1.png");
		Engine::TextureManager::AddTexture("Explosion", "Assets/2D Galaxy Assets/Game/Sprites/Explosion/Explosion_00019.png");
		Engine::TextureManager::AddTexture("Ground01", "Assets/Sprites/floor_sand_rock_0.png");
		Engine::TextureManager::AddTexture("Ground02", "Assets/Sprites/floor_sand_rock_1.png");
		Engine::TextureManager::AddTexture("Ground03", "Assets/Sprites/floor_sand_rock_2.png");
		Engine::TextureManager::AddTexture("Ground04", "Assets/Sprites/floor_sand_rock_3.png");
		Engine::TextureManager::AddTexture("Obstacle01", "Assets/Sprites/Enviroment/bars_red_2.png");
	}

	Map* map;
	Player* player;
	static MainScene* mainScene;
	void Update() override;
	void Render() override;
private:
	void Start() override;
	void CreateEnemy();
	std::vector<Enemy*> enemy;
	Engine::Vector2D RandomeStartPos();

	void CreatePlayer();

	//trying different techniques to create tilemap (um)
	void CreateMap();
	
	// Inherited via Scene
	virtual void SetUpUI() override;
};

