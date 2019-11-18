#include "Enemy.h"
#include <InputManager.h>
#include <Vector2D.h>
#include <Time.h>
#include <iostream>
#include "AI.h"
#include "Player.h"


void Enemy::Update()
{
	Engine::Entity::Update();
	Movement();

}

void Enemy::Movement()
{
	/*if (&player->position != nullptr)
	{
		if (ai->EnterDangerZone(30.0f, position, *player->position))
		{
			ai->pathFinding(*player->position, position);
		}
		else
			ai->RandomMovement();
	}*/
		
}


void Enemy::OnCollisionEnter(Engine::Collider* other)
{
	std::cout << other->tag << std::endl;
}


