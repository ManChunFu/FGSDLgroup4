#include "Enemy.h"
#include <InputManager.h>
#include <Vector2D.h>
#include <Time.h>
#include <iostream>
#include "Player.h"
#include "MainScene.h"
#include <GameTime.h>
#include <thread>


void Enemy::Update()
{
	/*std::thread t(&Enemy::Movement, this);
	t.detach();*/
	
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
	frameCounter += Engine::GameTime::DeltaTime();

	if (OnTriggerEnter())
	{
		std::cout << "Alert!";

		if (frameCounter > 1.f )//&& pathFindingPosition != player->position)
		{
			//pathFindingPosition = player->position;
			frameCounter = 0.f;
			pathToTarget = ai.pathFinding(player->position, position);//pathFindingPosition, position);
			pathCounter = 3;
		}

		if (pathToTarget.size() > pathCounter)
		{
			position = pathToTarget[pathToTarget.size() - pathCounter];
			pathCounter+= 2;
		}
		/*else
			goto moveRandom;*/

	}
	else
	{
		//moveRandom:
		randomCounter += Engine::GameTime::DeltaTime();
		if (randomCounter > 1.f)
		{
			randomCounter = 0.f;
			positionTemp = ai.RandomMovement();
		}
		newPosition = position + positionTemp;
		animator.Trigger("Run");

		if (newPosition.X < 0)
			newPosition.X = 2;
		else if (newPosition.X > 1440)
			newPosition.X = 1438;

		if (newPosition.Y < 0)
			newPosition.Y = 2;
		else if (newPosition.Y > 900)
			newPosition.Y = 898;
		
		position = newPosition;

	}
}

bool Enemy::OnTriggerEnter()
{
	return (ai.EnterDangerZone(300.0f, position, player->position));
}


void Enemy::OnCollisionEnter(Engine::Collider* other)
{
	//std::cout << other->tag << std::endl;
}


