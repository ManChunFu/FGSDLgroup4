#pragma once
#include <Entity.h>
#include <string>
#include <Vector2D.h>

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
	Enemy(int hp) : Engine::Entity()
	{
		hitpoint = hp;
	};


	float speed = 100.0f;
	int hitpoint;
	void Update() override;
	void Movement();
private:
	void OnCollisionEnter(Engine::Collider* other) override;
	Engine::InputManager* inputManager = nullptr;
	AI* ai = nullptr;
	Player* player = nullptr;
};

