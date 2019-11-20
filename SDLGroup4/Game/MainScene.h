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
		sceneCam.Position.X = 100;
		sceneCam.Position.Y = 100;
		Engine::TextureManager::AddTexture("Enemy", "Assets/Sprites/enemy.png");
		Engine::TextureManager::AddTexture("EnemyRun", "Assets/Sprites/Run.png");
		Engine::TextureManager::AddTexture("FireSpell", "Assets/Sprites/FireSpell.png");
		Engine::TextureManager::AddTexture("Player", "Assets/Sprites/Hopping_rabbit_dude.png");
		Engine::TextureManager::AddTexture("Projectile1", "Assets/Sprites/laserX.png");
		Engine::TextureManager::AddTexture("Projectile2", "Assets/Sprites/laserY.png");
		Engine::TextureManager::AddTexture("Explosion", "Assets/2D Galaxy Assets/Game/Sprites/Explosion/Explosion_00019.png");
		createPlayer(); 
		CreateEnemy(); 
	}

	Player* player;
	static MainScene* mainScene;
	void Update() override;
private:
	void CreateEnemy();
	std::vector<Enemy*> enemy;
	Engine::Vector2D RandomeStartPos();

	void createPlayer();
	
	// Inherited via Scene
	virtual void SetUpUI() override;
};

