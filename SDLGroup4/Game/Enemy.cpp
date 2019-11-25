#include "Enemy.h"
#include <InputManager.h>
#include <Vector2D.h>
#include <Time.h>
#include <iostream>
#include "Player.h"
#include "MainScene.h"
#include <GameTime.h>
#include <thread>

bool Enemy::hasPathFound;
void Enemy::Update()
{
	Movement();
	if (hitpoint < 1) Engine::Scene::ActiveScene->Destroy(this);
	Engine::Entity::Update();
}

void Enemy::Movement()
{
	Engine::Vector2D newPosition;
	frameCounter += Engine::GameTime::DeltaTime();
	collider->solid = true;
	if (OnTriggerEnter())
	{
		movementTimer ++;
		if (frameCounter > 0.5f && !hasPathFound)
		{
			hasPathFound = true;
			frameCounter = 0.f;
			pathToTarget = ai.pathFinding(player->position, position);
			pathCounter = 2;
		}

		if (pathToTarget.size() > pathCounter && movementTimer % 2 == 0)
		{
			movementTimer = 0;
			position = pathToTarget[pathToTarget.size() - pathCounter];
			pathCounter ++;
		}

	}
	else
	{
		randomCounter += Engine::GameTime::DeltaTime();
		if (randomCounter > 1.f)
		{
			randomCounter = 0.f;
			positionTemp = ai.RandomMovement();
		}
		newPosition = position + positionTemp;

		if (newPosition.X < 0)
			newPosition.X = 2;
		else if (newPosition.X > 1440)
			newPosition.X = 1438;

		if (newPosition.Y < 0)
			newPosition.Y = 2;
		else if (newPosition.Y > 900)
			newPosition.Y = 898;

		position = newPosition;

		
			animator.Stop();
			animator.Trigger("Walk");
		
		
	}
}

bool Enemy::OnTriggerEnter()
{
	return (ai.EnterDangerZone(300.0f, position, player->position));
}


void Enemy::OnCollisionEnter(Engine::Collider* other)
{
	if (other->tag == "Spell") 
	{
		std::cout << "Hit!";
		hitpoint--;
	}
	if (other->tag == "Player")
	{
		std::cout << "Player!";
	}
}


