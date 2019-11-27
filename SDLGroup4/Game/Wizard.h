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
}
class Wizard : public Engine::Entity
{
public:
	Wizard(int hp) : Engine::Entity()
	{
		player = MainScene::mainScene->player;
		hitpoint = hp;
		AddSprite("Wizard");
		AddCollider("Wizard", true);
		animator.Animations.push_back(new Engine::Animation("WizardIdle", "Idle", 5, 1, 5, false, destRect));
		animator.Animations.push_back(new Engine::Animation("WizardWalk", "Walk", 5, 1, 5, false, destRect));
		animator.Animations.push_back(new Engine::Animation("WizardAttack", "Attack", 5, 1, 5, true, destRect));
		animator.Animations.push_back(new Engine::Animation("WizardHurt", "Hurt", 5, 1, 5, true, destRect));
		animator.Trigger("Idle");
		PlayAnimation = true;
	}

private:
	void OnCollisionEnter(Engine::Collider* other) override;
	void Update() override;
	void Movement();
	bool OnTriggerEnter();

	int hitpoint;
	float randomCounter = 0;
	bool isHurt = false;
	Engine::Vector2D positionTemp;
	AI ai;
	Player* player;

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
