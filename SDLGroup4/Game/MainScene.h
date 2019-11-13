#pragma once
#include <Scene.h>
#include <vector>
class Enemy;
class MainScene : public Engine::Scene
{
public:
	MainScene(Engine::Application* app, Engine::InputManager* input) : Scene(app, input) { mainScene = this; }
	static MainScene* mainScene;
	void Update() override;
private:
	void CreateEnemy();
	std::vector<Enemy*> enemy;

	// Inherited via Scene
	virtual void SetUpUI() override;
};

