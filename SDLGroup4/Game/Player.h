#pragma once
#include <Entity.h>
#include <Slider.h>
#include "MainScene.h"|
#include <UIManager.h>
class TimedExplosive;
namespace Engine 
{
	class InputManager;
	class Animator;
	class CollisionManager;
	class Vector2D;
	class TextureManager;
	class Projectile;
	class Scene;
}

class Enemy;
class Player : public Engine :: Entity
{
public:
	Player(Engine::InputManager* input, int playerHP) : Engine::Entity() 
	{ 

		hitPoint = playerHP; 
		inputManager = input;
		AddSprite("Player");
		AddCollider("Player", true);
		animator.Animations.push_back(new Engine::Animation("PlayerIdle", "Idle", 5, 1, 3, false, destRect));
		animator.Animations.push_back(new Engine::Animation("PlayerRun", "Run", 5, 1, 15, false, destRect));
		animator.Animations.push_back(new Engine::Animation("PlayerAttack", "Attack", 5, 1, 15, true, destRect));
		animator.Animations.push_back(new Engine::Animation("PlayerHurt", "Hurt", 5, 1, 15, true, destRect));
		animator.Animations.push_back(new Engine::Animation("PlayerDie", "Die", 17, 1, 15, true, destRect));
		animator.Trigger("Idle");
		PlayAnimation = true;
		hpSlider = new Engine::Slider("Hp", { 0, 150, 200, 255 }, { 50, 50, 300, 20 });
		Engine::UIManager::AddObjectsToCanvas(1, { hpSlider });
		hpSlider->amount = playerHP;
		lastDirection.X = 1;
	};


	void Update() override;

	float moveSpeed = normalSpeed;
	bool isDead = false;

private:
	Enemy* enemy = nullptr;
	Engine::InputManager* inputManager = nullptr;
	float normalSpeed = 300.0f;
	float teleportDistance = 15000.0f;
	int hitPoint;
	int dirX = 0;
	int dirY = 0;
	Engine::Slider* hpSlider;
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

	enum States
	{
		IDLE,
		RUNLEFT,
		RUNRIGHT,
		ATTACK,
		HURT,
		DIE
	};	

	States state;
	
	

	// Inherited via Entity
	virtual void OnCollisionEnter(Engine::Collider* other) override;
	virtual void OnCollisionExit(Engine::Collider* other) override;

};

