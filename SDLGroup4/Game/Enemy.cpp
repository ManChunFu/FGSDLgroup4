#include "Enemy.h"
#include <InputManager.h>
#include <Vector2D.h>
#include <Time.h>
#include <iostream>



void Enemy::OnCollisionEnter(Engine::Collider* other)
{
	std::cout << other->tag << std::endl;
}

void Enemy::Update()
{
	Engine::Entity::Update();

	if (collider->collisions.size() > 0)
	{
		for (auto col : collider->collisions)
			OnCollisionEnter(col);
	}
}




