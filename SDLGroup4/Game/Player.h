#pragma once
#include <Entity.h>
#include <Scene.h>
class TimedExplosive;
namespace Engine 
{
	class InputManager;
	class Animator;
	class CollisionManager;
	class Vector2D;
	class TextureManager;
	class Projectile;
}

class Player : public Engine :: Entity
{
public:
	Player(Engine::InputManager* input, int playerHP) : Engine::Entity() 
	{ 
		hitPoint = playerHP; 
		inputManager = input; 
		animator.Animations.push_back(new Engine::Animation("PlayerIdle", "Idle", 5, 1, 3, false));
		animator.Animations.push_back(new Engine::Animation("PlayerRun", "Run", 5, 1, 12, false));
		animator.Animations.push_back(new Engine::Animation("PlayerAttack", "Attack", 5, 1, 10, true));
		animator.Trigger("Idle");
		PlayAnimation = true;

		lastDirection.X = 1;
	};


	void Update() override;

	float moveSpeed = normalSpeed;

private:
	Engine::InputManager* inputManager = nullptr;
	float normalSpeed = 200.0f;
	float teleportDistance = 15000.0f;
	int hitPoint = 0;
	int dirX = 0;
	int dirY = 0;
	Engine::Vector2D lastDirection;
	TimedExplosive* bullet = nullptr;
	Engine::Vector2D currPos;
	float mineCooldown = 5;
	float mineTimer = 0;
	float teleportCooldown = 3.0f;
	float teleportTimer;
	bool hasTeleported;
	Engine::Projectile* projectile = nullptr; //alternative for shooting (um)
	float shootTimer = 0;
	void MovePlayer();
	void Shoot();
	
	

	// Inherited via Entity
	virtual void OnCollisionEnter(Engine::Collider* other) override;

};

