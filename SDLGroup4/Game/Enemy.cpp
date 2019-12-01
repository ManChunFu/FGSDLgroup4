#include "Enemy.h"
#include <InputManager.h>
#include <Vector2D.h>
#include <Time.h>
#include <iostream>
#include "Player.h"
#include <GameTime.h>
#include <SoundManager.h>
bool Enemy::hasPathFound;
void Enemy::Update()
{
	if (state != DIE)
		Movement();
	if (player->isDead)
	{
		if (state == ATTACK)
		{
			animator.Stop();
			animator.Trigger("Idle");
		}
	}
	soundDelayHurt += Engine::GameTime::DeltaTime();
	if (position.X < 0) position.X = 0;
	if (position.X > 1440 - (destRect.w)) position.X = 1440 - destRect.w;
	if (position.Y < 0) position.Y = 0;
	if (position.Y > 900 - (destRect.h)) position.Y = 900 - destRect.h;

	Engine::Entity::Update();


	if (hitpoint < 1 && state != DIE)
	{
		animator.Stop();
		animator.Trigger("Die");
		if (troll) Engine::SoundManager::PlaySoundEffect("TrollDeath", 0, 8);
		else Engine::SoundManager::PlaySoundEffect("KnightDeath", 0, 8);
		state = DIE;
		collider->solid = false;
	}

	if (state == DIE && animator.CurrenAnimation->StopPlaying)
	{
		if (troll) Tracker::Score += 50;
		else Tracker::Score += 100;

		Tracker::Enemies--;
		Engine::Scene::ActiveScene->Destroy(this);
	}
}

void Enemy::Movement()
{
	frameCounter += Engine::GameTime::DeltaTime();
	collider->solid = true;
	if (OnTriggerEnter())
	{
		movementTimer++;
		if (frameCounter > 0.5f && !hasPathFound)
		{
			hasPathFound = true;
			frameCounter = 0.f;
			pathToTarget = ai.CallPathFinding(player->position, position);
			pathCounter = 2;
			isHurt = false;
		}
		if (pathToTarget.size() == 0) {
			RandomMovement();
			return;
		}

		if (pathToTarget.size() > pathCounter && !isHurt)
		{
			if (state != ATTACK)
			{
				movementTimer = 0;
				position = pathToTarget[pathToTarget.size() - pathCounter];
				pathCounter++;
				if (position.X > lastDirectionX)
				{
					if (state != RUNRIGHT && state != ATTACK)
					{
						animator.Stop();
						animator.Trigger("Run");
						spriteFlip = SDL_FLIP_NONE;
						state = RUNRIGHT;
					}
				}
				else if (position.X < lastDirectionX)
				{
					if (state != RUNLEFT && state != ATTACK)
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
			}
			if (ai.GetDistance(position, player->position) < destRect.w + 30)
			{
				if (position.X - player->position.X > 0)
				{
					if (ai.GetDistance(position, player->position) < destRect.w + 30)
					{
						if (animator.CurrenAnimation->StopPlaying)
						{
							player->Hurt();
						}
						if (state != ATTACK || (animator.CurrenAnimation->StopPlaying && state == ATTACK))
						{
							if (troll)
							{
								if (soundDelay > 1)
								{
									soundDelay = 0;
									Engine::SoundManager::PlaySoundEffect("EnemyAttack", 0, 15);
								}
								else soundDelay++;
							}
							else { Engine::SoundManager::PlaySoundEffect("KnightAttack", 0, 8); }
							animator.Stop();
							animator.Trigger("Attack");
							spriteFlip = SDL_FLIP_HORIZONTAL;
						}
						state = ATTACK;
						return;
					}
				}
				if (animator.CurrenAnimation->StopPlaying)
				{
					player->Hurt();
				}
				if (state != ATTACK || (animator.CurrenAnimation->StopPlaying && state == ATTACK))
				{
					if (troll)
					{
						if (soundDelay > 1)
						{
							soundDelay = 0;
							Engine::SoundManager::PlaySoundEffect("EnemyAttack", 0, 15);
						}
						else soundDelay++;
					}
					else { Engine::SoundManager::PlaySoundEffect("KnightAttack", 0, 8); }
					animator.Stop();
					animator.Trigger("Attack");
					state = ATTACK;
				}
				spriteFlip = SDL_FLIP_NONE;
				return;
			}
			else state = IDLE;
			lastDirectionX = position.X;

		}

	}
	else
	{
		RandomMovement();
	}
}

bool Enemy::OnTriggerEnter()
{
	return (ai.EnterDangerZone(450.0f, position, player->position));
}


void Enemy::OnCollisionEnter(Engine::Collider* other)
{
	if (state != DIE)
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
			if (soundDelayHurt > 1)
			{
				if (troll) Engine::SoundManager::PlaySoundEffect("TrollHurt", 0, 14, 2);
				else Engine::SoundManager::PlaySoundEffect("KnightHurt", 0, 14, 2);
				soundDelayHurt = 0;
			}
		}
	}
}

void Enemy::OnCollisionExit(Engine::Collider* other)
{
}

void Enemy::OnDestroy()
{}

void Enemy::RandomMovement()
{
	Engine::Vector2D newPosition;
	if (animator.CurrenAnimation->RunFullClip)
		return;

	randomCounter += Engine::GameTime::DeltaTime();

	if (randomCounter > 1.f)
	{
		randomCounter = 0.f;
		positionTemp = ai.RandomMovement();
	}
	newPosition = position + positionTemp;

	for (auto obstacle : MainScene::obstacle)
	{
		if (obstacle->position.X + obstacle->destRect.w >= newPosition.X &&
			newPosition.X + destRect.w >= obstacle->position.X &&
			obstacle->position.Y + obstacle->destRect.h >= newPosition.Y &&
			newPosition.Y + destRect.h >= obstacle->position.Y)
		{
			return;
		}
	}

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




