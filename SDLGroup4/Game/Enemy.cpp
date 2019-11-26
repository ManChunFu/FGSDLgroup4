#include "Enemy.h"
#include <InputManager.h>
#include <Vector2D.h>
#include <Time.h>
#include <iostream>
#include "Player.h"
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
			Attack = false;
			isHurt = false;
		}

		if (pathToTarget.size() > pathCounter && !Attack && !isHurt)//&& movementTimer % 2 == 0)
		{
			movementTimer = 0;
			position = pathToTarget[pathToTarget.size() - pathCounter];
			pathCounter++;
			if (position.X > lastDirectionX)
			{
				if (state != RUNRIGHT)
				{
					animator.Stop();
					animator.Trigger("Run");
					spriteFlip = SDL_FLIP_NONE;
					state = RUNRIGHT;
				}
			}
			else if (position.X < lastDirectionX)
			{
				if (state != RUNLEFT)
				{
					animator.Stop();
					animator.Trigger("Run");
					spriteFlip = SDL_FLIP_HORIZONTAL;
					state = RUNLEFT;
				}
			}
			else
			{
				animator.Stop();
				animator.Trigger("Run");
			}
			
			if (Distance(position, player->position) < 120 )
			{
				if (state == RUNLEFT)
				{
					if (Distance(position, player->position) < 50)
					{
						collider->solid = false;
						animator.Stop();
						//position.Y -= 43.f; // sprite pivot fixed in a ugly way
						animator.Trigger("Attack");
						Attack = true;
						return;
					}
				}
				else
				{
					collider->solid = false;
					animator.Stop();
					//position.Y -= 43.f;
					animator.Trigger("Attack");
					Attack = true;
					return;
				}
			}
			
			lastDirectionX = position.X;
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
		{
			animator.Stop();
			animator.Trigger("Walk");
		}
		position = newPosition;
	}
}

bool Enemy::OnTriggerEnter()
{
	return (ai.EnterDangerZone(450.0f, position, player->position));
}


void Enemy::OnCollisionEnter(Engine::Collider* other)
{
	if (other->tag == "Spell")
	{
		if (state != HURT)
		{
			animator.Stop();
			animator.Trigger("Hurt");
			isHurt = true;
			state = HURT;
		}
		hitpoint--;
	}
}

float Enemy::Distance(Engine::Vector2D position, Engine::Vector2D targetPosition)
{
	float distance = _hypotf(fabsf(targetPosition.X - position.X), fabsf(targetPosition.Y - position.Y));
	return distance;
}


