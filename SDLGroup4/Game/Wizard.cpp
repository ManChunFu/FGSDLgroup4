#include "Wizard.h"
#include <GameTime.h>
#include "Player.h"

void Wizard::OnCollisionEnter(Engine::Collider* other)
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

void Wizard::Update()
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

	if (position.X < 0) position.X = 0;
	if (position.X > 1440 - (destRect.w)) position.X = 1440 - destRect.w;
	if (position.Y < 0) position.Y = 0;
	if (position.Y > 900 - (destRect.h)) position.Y = 900 - destRect.h;

	Engine::Entity::Update();
}

void Wizard::Movement()
{
	Engine::Vector2D newPosition;
	if (OnTriggerEnter())
	{
		if (state != ATTACK)
		{
			animator.Stop();
			animator.Trigger("Attack");
			state = ATTACK;
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

bool Wizard::OnTriggerEnter()
{
	return (ai.EnterDangerZone(300.0f, position, player->position));
}
