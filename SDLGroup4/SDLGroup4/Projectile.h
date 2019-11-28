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
		Projectile(float lifeSpan, const Engine::Vector2D& startPos, float _dirX, float _dirY, bool _affectsEnemies) :
			Engine::Entity()
		{
			dirX = _dirX;
			dirY = _dirY;
			position = startPos;
			affectsEnemies = _affectsEnemies;
			AddSprite("IceBallSprite");
			if(affectsEnemies) animator.Animations.push_back(new Engine::Animation("IceBall", "Projectile", 3, 1, 10, true, destRect));
			else animator.Animations.push_back(new Engine::Animation("FireBall", "Projectile", 3, 1, 10, true, destRect));
			if(affectsEnemies) AddCollider("Spell", false);
			else AddCollider("EnemySpell", false);
			PlayAnimation = true;
			animator.Trigger("Projectile");
		}

		void Update() override;

	private:
		void OnCollisionEnter(Collider* other) override;
		int shootX = 400;
		int shootY = 400;
		bool affectsEnemies;
		float dirX;
		float dirY;

		float lifeSpan = 0;

	};

	
}