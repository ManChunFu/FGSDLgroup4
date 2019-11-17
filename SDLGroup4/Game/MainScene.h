#pragma once
#include <Scene.h>
#include <vector>
#include <Vector2D.h>

class Obsticale;
class Player;
class Enemy;
class MainScene : public Engine::Scene
{
public:
	MainScene(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) 
	{ 
		mainScene = this; 
		createPlayer(); 
		CreateEnemy(); 
	}

	static MainScene* mainScene;
	void Update() override;
	std::vector<Engine::Vector2D> ObstacleList;
private:
	void CreateEnemy();
	std::vector<Enemy*> enemy;

	Player* player;
	void createPlayer();
	
	// Inherited via Scene
	virtual void SetUpUI() override;
};

