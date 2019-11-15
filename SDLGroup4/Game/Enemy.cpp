#include "Enemy.h"
#include <InputManager.h>
#include <Vector2D.h>
#include <Time.h>
#include <iostream>





void Enemy::Update()
{
	Engine::Entity::Update();

	
}


void Enemy::OnCollisionEnter(Engine::Collider* other)
{
}

void Enemy::MovePlayer()
{
	Engine::Time::DeltaTime();
	Engine::Vector2D movement;
	

	
}
