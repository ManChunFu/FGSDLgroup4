#pragma once
#include <Entity.h>
class Bullet : public Engine::Entity
{
public:
	Bullet(float lifespan, const Engine::Vector2D& startPos) : Engine::Entity()
	{
		position = startPos;
		lifeSpan = lifespan;
	}
	~Bullet() override { Engine::Entity::~Entity(); }
	void Update() override;
private:
	int speed = 200;
	float lifeSpan = 0;
	float explosionTimer = 2;
};

