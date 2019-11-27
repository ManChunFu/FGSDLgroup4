#pragma once
#include <Entity.h>
#include <string>
#include <Vector2D.h>
#include "AI.h"
#include "MainScene.h"
#include <string>
#include "Tracker.h"
namespace Engine
{
	class Collider;
	class Scene;
}

class Player;
class AI;

class Enemy : public Engine::Entity
{
public:
	Enemy(int hp) : Engine::Entity() {
		hitpoint = hp;
		AddSprite("Enemy");
		AddCollider("Enemy", true);
		player = MainScene::mainScene->player;
		animator.Animations.push_back(new Engine::Animation("EnemyIdle", "Idle", 7, 1, 5, false, destRect));
		animator.Animations.push_back(new Engine::Animation("EnemyWalk", "Walk", 7, 1, 10, false, destRect));
		animator.Animations.push_back(new Engine::Animation("EnemyRun", "Run", 7, 1, 12, false, destRect));
		animator.Animations.push_back(new Engine::Animation("EnemyAttack", "Attack", 7, 1, 12, true, destRect));
		animator.Animations.push_back(new Engine::Animation("EnemyHurt", "Hurt", 7, 1, 20, true, destRect));
		animator.Animations.push_back(new Engine::Animation("EnemyDie", "Die", 12, 1, 10, true, destRect));
		animator.Trigger("Idle");
		PlayAnimation = true;
		Tracker::Enemies++;
	}
	~Enemy() {};
	int hitpoint;
	void Update() override;
	void Movement();
	bool OnTriggerEnter();
	static bool hasPathFound;
	bool Attack = false;
	

private:
	void OnCollisionEnter(Engine::Collider* other) override;
	void OnCollisionExit(Engine::Collider* other) override;
	void OnDestroy() override;
	AI ai;
	Player* player = nullptr;
	std::vector<Engine::Vector2D> pathToTarget;
	Engine::Vector2D positionTemp;
	float randomCounter = 0.f;
	int pathCounter = 2;
	float frameCounter = 0.f;
	int movementTimer = 0;
	float lastDirectionX;
	bool isHurt = false;
	
	enum States
	{
		IDLE,
		WALKLEFT,
		WALKRIGHT,
		RUNLEFT,
		RUNRIGHT,
		ATTACK,
		HURT,
		DIE
	};

	States state;
};

