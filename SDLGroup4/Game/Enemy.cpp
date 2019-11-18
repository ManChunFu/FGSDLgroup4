#include "Enemy.h"
#include <InputManager.h>
#include <Vector2D.h>
#include <Time.h>
#include <iostream>
#include "Player.h"
#include "MainScene.h"


void Enemy::Update()
{
	Movement();
	OnTriggerEnter();

	if (position.X < 0) position.X = 0;
	if (position.X > 1440 - destRect.w) position.X = 1440 - destRect.w;
	if (position.Y < 0) position.Y = 0;
	if (position.Y > 900 - destRect.h) position.Y = 900 - destRect.h;

	Engine::Entity::Update();

}

void Enemy::Movement()
{
	Engine::Vector2D currentPos;
	currentPos.X = position.X;
	if (!OnTriggerEnter())
	{
		Engine::Vector2D positionTemp = ai.RandomMovement();
		if (position.X <= 0)
		{

		}
		
	}
	else
	{
		std::cout << "Alert!";
		/*pathToTarget = ai.pathFinding(player->position, position);
		for (auto path : pathToTarget)
		{
			position.X += path.X;
			position.Y += path.Y;
		}*/
	}
}

bool Enemy::OnTriggerEnter()
{
	return (ai.EnterDangerZone(200.0f, position, player->position));
}


void Enemy::OnCollisionEnter(Engine::Collider* other)
{
	//std::cout << other->tag << std::endl;
}


