#pragma once
#include <Entity.h>
#include "MainScene.h"
#include <Vector2D.h>
#include "AI.h"

namespace Engine
{
	class Collider;
	class Scene;
	class AI;
	class Player;
	class Projectile;
}
class Wizard : public Engine::Entity
{
public:
	Wizard(int hp) : Engine::Entity()
	{
		player = MainScene::mainScene->player;
		hitpoint = hp;
		AddSprite("Wizard");
		AddCollider("Enemy", true);
		animator.Animations.push_back(new Engine::Animation("WizardIdle", "Idle", 5, 1, 5, false, destRect));
		animator.Animations.push_back(new Engine::Animation("WizardWalk", "Walk", 5, 1, 5, false, destRect));
		animator.Animations.push_back(new Engine::Animation("WizardAttack", "Attack", 5, 1, 10, true, destRect));
		animator.Animations.push_back(new Engine::Animation("WizardHurt", "Hurt", 5, 1, 5, true, destRect));
		animator.Animations.push_back(new Engine::Animation("WizardDie", "Die", 8, 1, 5, true, destRect));
		animator.Trigger("Idle");
		PlayAnimation = true;
	}

private:
	void OnCollisionEnter(Engine::Collider* other) override;
	void OnCollisionExit(Engine::Collider* other) override;
	void Update() override;
	void Movement();
	bool OnTriggerEnter();
	void Shoot();
	Engine::Projectile* projectile;
	int hitpoint;
	float randomCounter = 0;
	Engine::Vector2D positionTemp;
	AI ai;
	Player* player;
	float shootTimer = 5;
	enum States
	{
		IDLE,
		WALKLEFT,
		WALKRIGHT,
		ATTACK,
		HURT,
		DIE
	};

	States state;
};
