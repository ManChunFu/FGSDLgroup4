#pragma once
#include <Entity.h>
#include <Scene.h>
//#include <InputManager.h>
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
	{ hitPoint = playerHP; inputManager = input; };


	void Update() override;

	float moveSpeed = 500.0f;

private:
	Engine::InputManager* inputManager = nullptr;
	Engine::Animator* anim = nullptr;

	int hitPoint = 0;
	int dirX = 0;
	int dirY = 0;
	TimedExplosive* bullet = nullptr;
	Engine::Vector2D currPos;
	float mineCooldown = 5;
	float mineTimer = 0;
	Engine::Projectile* projectile = nullptr; //alternative for shooting (um)


	
	void MovePlayer();
	


	// Inherited via Entity
	virtual void OnCollisionEnter(Engine::Collider* other) override;

};

