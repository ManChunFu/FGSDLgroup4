#pragma once
#include <Entity.h>
#include "MainScene.h"

namespace Engine
{
	class Collider;
	class Scene;
}
class Wizard : public Engine::Entity
{
public:
	Wizard(int hp) : Engine::Entity()
	{
		hitpoint = hp;
		AddSprite("Wizard");
		AddCollider("Wizard", true);
		animator.Animations.push_back(new Engine::Animation("WizardIdle", "Idle", 5, 1, 5, false, destRect));
		animator.Trigger("Idle");
		PlayAnimation = true;
	}

private:
	int hitpoint;
	void Update() override;
	void Movement();
	bool OnTriggerEnter();
};
