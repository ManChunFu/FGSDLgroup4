#pragma once
#include <Scene.h>
#include <vector>
#include "Player.h"


class Player;

class Enemy;
class MainScene : public Engine::Scene
{
public:
	MainScene(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) { mainScene = this; createPlayer(); }
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

