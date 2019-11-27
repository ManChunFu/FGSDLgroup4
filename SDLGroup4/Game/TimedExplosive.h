#pragma once
#include <Entity.h>
class TimedExplosive : public Engine::Entity
{
public:
	TimedExplosive(float lifespan, const Engine::Vector2D& startPos) : Engine::Entity()
	{
		position = startPos;
		lifeSpan = lifespan;
		this->AddSprite("FireSpell");
	}
	void Update() override;
private:
	int speed = 200;
	float lifeSpan = 0;
	float explosionTimer = 2;
};

