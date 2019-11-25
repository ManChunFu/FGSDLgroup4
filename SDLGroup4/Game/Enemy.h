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
		animator.Animations.push_back(new Engine::Animation("EnemyIdle", "Idle", 7, 1, 5, false));
		animator.Animations.push_back(new Engine::Animation("EnemyWalk", "Walk", 7, 1, 10, false));
		animator.Trigger("Idle");
		PlayAnimation = true;
	}

	int hitpoint;
	void Update() override;
	void Movement();
	bool OnTriggerEnter();
	static bool hasPathFound;
	

private:
	void OnCollisionEnter(Engine::Collider* other) override;
	Engine::InputManager* inputManager = nullptr;
	AI ai;
	Player* player = nullptr;
	std::vector<Engine::Vector2D> pathToTarget;
	Engine::Vector2D positionTemp;
	float randomCounter = 0.f;
	int pathCounter = 2;
	float frameCounter = 0.f;
	int movementTimer = 0;
	int animationID = 0; // 0 = Idle, 1 = Walk, 2 = Run
	


};

