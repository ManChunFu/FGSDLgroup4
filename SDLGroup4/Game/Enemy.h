#pragma once
#include <Entity.h>
#include <string>
#include <Vector2D.h>
#include "AI.h"
#include "MainScene.h"
#include <string>
namespace Engine
{
	class InputManager;
	class Collider;
	class Scene;
}

class Player;
class AI;

class Enemy : public Engine::Entity
{
public:
	Enemy(int hp) : Engine::Entity() {
		player = MainScene::mainScene->player;
		hitpoint = hp;
		animator.Animations.push_back(new Engine::Animation("EnemyRun", "Run", 8, 1, 5));
		PlayAnimation = true;
		ScaleX = .5f;
		ScaleY = 0.5f;
	}

	int hitpoint;
	void Update() override;
	void Movement();
	bool OnTriggerEnter();
	

private:
	void OnCollisionEnter(Engine::Collider* other) override;
	Engine::InputManager* inputManager = nullptr;
	AI ai;
	Player* player = nullptr;
	std::vector<Engine::Vector2D> pathToTarget;
	Engine::Vector2D positionTemp;
	float randomCounter = 0.f;
	int pathCounter = 3;
	float frameCounter = 0.f;
	Engine::Vector2D pathFindingPosition;
	


};

