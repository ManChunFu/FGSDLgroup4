#pragma once
#include <Scene.h>
#include <vector>
#include <TextureManager.h>
#include "Map.h"
#include "Obstacle.h"
#include <Text.h>
#include "EnemySpawner.h"
class Player;
class Enemy;
class Map;
class Obstacle;
class Wizard;
class MainScene : public Engine::Scene
{
public:
	MainScene(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) 
	{ 
		mainScene = this; 
		Engine::UIManager::CreateCanvas({ 0,0,0,0 }, { 0, 0, 250, 150 });
		scoreText = new Engine::Text("Assets/Fonts/BAUHS93.ttf", 50, "Score: ", { 0, 0, 0, 255 }, { 50, 50, 900, -100 });
		Engine::UIManager::AddObjectsToCanvas(1, { scoreText });
		spawner = new EnemySpawner();
	}

	/*Obstacle* obstacle;*/
	std::vector<Obstacle*>obstacle;
	Map* map; 
	Player* player;
	std::vector<Enemy*> enemy;
	Wizard* wizard;
	static MainScene* mainScene;
	void Update() override;
	void Render() override;
	
private:
	void Start() override;
	Engine::Text* scoreText;
	EnemySpawner* spawner;
	void CreateObstacle();
	void CreatePlayer();
	Engine::Vector2D ObstaclePlacement(Engine::Vector2D pos);
	Engine::Vector2D lastPosition;
	//trying different techniques to create tilemap (um)
	void CreateMap();
	
	// Inherited via Scene
	virtual void SetUpUI() override;
};

