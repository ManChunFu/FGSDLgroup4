#include "Enemy.h"
#include <InputManager.h>
#include <Vector2D.h>
#include <Time.h>
#include <iostream>
#include "Player.h"
#include "MainScene.h"
#include <GameTime.h>


void Enemy::Update()
{
	Movement();

	/*if (position.X < 0) position.X = 0;
	if (position.X > 1440 - destRect.w) position.X = 1440 - destRect.w;
	if (position.Y < 0) position.Y = 0;
	if (position.Y > 900 - destRect.h) position.Y = 900 - destRect.h;*/

	Engine::Entity::Update();

}

void Enemy::Movement()
{
	Engine::Vector2D newPosition;

	Engine::Vector2D positionTemp = ai.RandomMovement();
	newPosition = position + positionTemp;

	if (newPosition.X <= 0)
		newPosition.X++;
	else if (newPosition.Y <= 0)
		newPosition.Y++;
	else if (position.X >= 1440)
		newPosition.X--;
	else if (position.Y >= 900)
		newPosition.Y--;
	else
		position = newPosition;


	if (OnTriggerEnter())
	{
		std::cout << "Alert!";
		/*pathToTarget = ai.pathFinding(player->position, position);
		for (auto path : pathToTarget)
		{
			
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


