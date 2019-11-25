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
	if (position.X < 0) position.X = 0;
	if (position.X > 1440 - (destRect.w)) position.X = 1440 - destRect.w;
	if (position.Y < 0) position.Y = 0;
	if (position.Y > 900 - (destRect.h)) position.Y = 900 - destRect.h;

	Engine::Entity::Update();
	if (hitpoint < 1)
		Engine::Scene::ActiveScene->Destroy(this);
}

void Enemy::Movement()
{
	Engine::Vector2D newPosition;
	frameCounter += Engine::GameTime::DeltaTime();
	collider->solid = true;
	if (OnTriggerEnter())
	{
		movementTimer++;
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
			pathCounter++;
			
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

		if (positionTemp.X == 0 && positionTemp.Y == 0)
		{
			if (state != IDLE)
			{
				animator.Stop();
				animator.Trigger("Idle");
				state = IDLE;
			}
		}
		else if (positionTemp.X > 0)
		{
			if (state != WALKRIGHT)
			{
				animator.Stop();
				animator.Trigger("Walk");
				spriteFlip = SDL_FLIP_NONE;
				state = WALKRIGHT;
			}
		}
		else if (positionTemp.X < 0)
		{
			if (state != WALKLEFT)
			{
				animator.Stop();
				animator.Trigger("Walk");
				spriteFlip = SDL_FLIP_HORIZONTAL;
				state = WALKLEFT;
			}
		}
		else
			animator.Trigger("Walk");

		position = newPosition;

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
		hitpoint--;
	}
}


