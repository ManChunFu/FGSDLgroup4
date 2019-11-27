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
		animator.Trigger("Idle");
		PlayAnimation = true;
	}

private:
	int hitpoint;
	void Update() override;
	void Movement();
	bool OnTriggerEnter();

	float randomCounter = 0;
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
