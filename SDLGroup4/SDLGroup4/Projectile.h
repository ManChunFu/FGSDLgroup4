#pragma once
#include "Entity.h"
#include <string>
#include "Vector2D.h"


namespace Engine {

	class Scene;
	class InputManager;

	class Projectile : public Engine::Entity
	{
	public:
		Projectile(float lifeSpan, const Engine::Vector2D& startPos, int _dirX, int _dirY) :
			Engine::Entity()
		{
			dirX = _dirX;
			dirY = _dirY;
			position = startPos;
			AddSprite("IceBallSprite");
			animator.Animations.push_back(new Engine::Animation("IceBall", "FireIce", 3, 1, 10, true, destRect));
			animator.Animations.push_back(new Engine::Animation("FireBall", "FireFire", 3, 1, 10, true, destRect));
			AddCollider("Spell", false);
			PlayAnimation = true;
		}

		void Update() override;

	private:
		void OnCollisionEnter(Collider* other) override;
		int shootX = 400;
		int shootY = 400;

		int dirX;
		int dirY;

		float lifeSpan = 0;

	};

	
}