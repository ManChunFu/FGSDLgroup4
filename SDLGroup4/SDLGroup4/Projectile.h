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
			animator.Animations.push_back(new Engine::Animation("IceBall", "FireIce", 3, 1, 10, true));
			animator.Animations.push_back(new Engine::Animation("FireBall", "FireFire", 3, 1, 10, true));
			AddSprite("IceBallSprite");
			AddCollider("Spell", false);
			PlayAnimation = true;
		}

		void Update() override;

	private:
		int shootX = 200;
		int shootY = 200;

		int dirX;
		int dirY;

		float lifeSpan = 0;

	};

	
}