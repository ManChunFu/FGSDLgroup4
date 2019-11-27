#pragma once
#include <Scene.h>
#include <vector>
#include <TextureManager.h>
#include "Map.h"
#include "Obstacle.h"
#include <Text.h>
class Player;
class Enemy;
class Map;
class Obstacle;

class MainScene : public Engine::Scene
{
public:
	MainScene(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) 
	{ 
		mainScene = this; 
		Engine::UIManager::CreateCanvas({ 0,0,0,0 }, { 0, 0, 250, 150 });
		scoreText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 50, "Score: ", { 0, 150, 150, 255 }, { 50, 50, 500, 80 });
		Engine::UIManager::AddObjectsToCanvas(1, { scoreText });
		Engine::TextureManager::AddTexture("Enemy", "Assets/Sprites/Enemy/sprite.png");
		Engine::TextureManager::AddTexture("EnemyIdle", "Assets/Sprites/Enemy/IDLE1.png");
		Engine::TextureManager::AddTexture("EnemyWalk", "Assets/Sprites/Enemy/WALK.png");
		Engine::TextureManager::AddTexture("EnemyRun", "Assets/Sprites/Enemy/RUN.png");
		Engine::TextureManager::AddTexture("EnemyAttack", "Assets/Sprites/Enemy/ATTACK.png");
		Engine::TextureManager::AddTexture("EnemyHurt", "Assets/Sprites/Enemy/HURT.png");
		Engine::TextureManager::AddTexture("EnemyDie", "Assets/Sprites/Enemy/DIE1.png");
		Engine::TextureManager::AddTexture("FireSpell", "Assets/Sprites/FireSpell.png");
		Engine::TextureManager::AddTexture("Player", "Assets/Sprites/Player/sprite.png");
		Engine::TextureManager::AddTexture("PlayerIdle", "Assets/Sprites/Player/IDLE.png");
		Engine::TextureManager::AddTexture("PlayerRun", "Assets/Sprites/Player/RUN.png");
		Engine::TextureManager::AddTexture("PlayerAttack", "Assets/Sprites/Player/ATTACK.png");
		Engine::TextureManager::AddTexture("PlayerHurt", "Assets/Sprites/Player/HURT.png");
		Engine::TextureManager::AddTexture("PlayerDie", "Assets/Sprites/Player/DIE1.png");
		Engine::TextureManager::AddTexture("IceBallSprite", "Assets/Sprites/Player/ICEBALLSprite.png");
		Engine::TextureManager::AddTexture("IceBall", "Assets/Sprites/Player/ICEBALL1.png");
		Engine::TextureManager::AddTexture("FireBall", "Assets/Sprites/player/FIREBALL1.png");
		Engine::TextureManager::AddTexture("Explosion", "Assets/2D Galaxy Assets/Game/Sprites/Explosion/Explosion_00019.png");
		Engine::TextureManager::AddTexture("Ground01", "Assets/Sprites/floor_sand_rock_0.png");
		Engine::TextureManager::AddTexture("Ground02", "Assets/Sprites/floor_sand_rock_1.png");
		Engine::TextureManager::AddTexture("Ground03", "Assets/Sprites/floor_sand_rock_2.png");
		Engine::TextureManager::AddTexture("Stone", "Assets/Sprites/Enviroment/stone_brick_1.png");
		Engine::TextureManager::AddTexture("Border", "Assets/Sprites/Enviroment/bars_red_2.png");
		Engine::TextureManager::AddTexture("Obstacle01", "Assets/Sprites/Enviroment/granite_statue.png");
	}

	/*Obstacle* obstacle;*/
	std::vector<Obstacle*>obstacle;
	Map* map; 
	Player* player;
	std::vector<Enemy*> enemy;
	static MainScene* mainScene;
	void Update() override;
	void Render() override;
	
private:
	void Start() override;
	Engine::Text* scoreText;
	void CreateEnemy();
	Engine::Vector2D RandomeStartPos();
	void CreateObstacle();
	void CreatePlayer();
	const int enemySpawnRate = 5;
	float enemySpawnTimer = 0.1f;
	Engine::Vector2D ObstaclePlacement(Engine::Vector2D pos);
	Engine::Vector2D lastPosition;
	//trying different techniques to create tilemap (um)
	void CreateMap();
	
	// Inherited via Scene
	virtual void SetUpUI() override;
};

