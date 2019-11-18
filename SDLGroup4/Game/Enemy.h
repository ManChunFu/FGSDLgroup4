#pragma once
#include <Entity.h>
#include <string>
#include <Vector2D.h>
#include "AI.h"
#include "MainScene.h"
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
};

