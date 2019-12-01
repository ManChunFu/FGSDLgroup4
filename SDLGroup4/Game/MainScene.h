#pragma once
#include <Scene.h>
#include <vector>
#include <TextureManager.h>
#include "Map.h"
#include "Obstacle.h"
#include <Text.h>
#include "EnemySpawner.h"
#include <Image.h>
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
		scoreText = new Engine::Text("Assets/Fonts/tt0861m_.ttf", 35, "SCORE: ", { 153, 0, 0, 255 }, { 50, 50, 900, -145 });
		Engine::UIManager::AddObjectsToCanvas(1, { scoreText });
		spawner = new EnemySpawner();
	}

	
	static std::vector<Obstacle*>obstacle;
	Map* map; 
	Player* player;
	static MainScene* mainScene;
	void Update() override;
	void Render() override;
	
private:
	void Start() override;
	Engine::Text* scoreText;
	EnemySpawner* spawner;
	void CreatePlayer();
	Engine::Vector2D lastPosition;
	void CreateMap();
	
	// Inherited via Scene
	virtual void SetUpUI() override;
};

