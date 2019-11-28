#include "Wizard.h"
#include <GameTime.h>
#include "Player.h"
#include "Tracker.h"
#include <Projectile.h>
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

	if (hitpoint < 1 && state != DIE)
	{
		animator.Stop();
		animator.Trigger("Die");
		state = DIE;
	}
	shootTimer -= Engine::GameTime::DeltaTime();
	
	

	if (state == DIE && animator.CurrenAnimation->StopPlaying)
	{
		Tracker::Score += 10;
		Engine::Scene::ActiveScene->Destroy(this);
	}

}

void Wizard::Movement()
{
	Engine::Vector2D newPosition;
	collider->solid = true;
	
		if (shootTimer < 0)
		{
			shootTimer = 3;
			animator.Stop();
			animator.Trigger("Attack");
			Shoot();
			state = ATTACK;
			if (player->position.X < position.X)
				spriteFlip = SDL_FLIP_HORIZONTAL;
			else
				spriteFlip = SDL_FLIP_NONE;
			
		}
	
	
		if (animator.CurrenAnimation->RunFullClip)
			return;
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

bool Wizard::OnTriggerEnter()
{
	return (ai.EnterDangerZone(300.0f, position, player->position));
}

void Wizard::Shoot()
{
	int numSpawners = 32;
	Engine::Vector2D projectilePos = position;
	double angle = 0;
	float xPosition;
	float yPosition;

	double rad = 150;

	for (int i = 0; i < numSpawners; i++)
	{
		angle = i * (360.0 / numSpawners) + 90.0;
		float degree = (angle * (M_PI / 180));
		xPosition = rad * cos(degree);
		yPosition = rad * sin(degree);
		float mag = sqrt((xPosition * xPosition) + (yPosition * yPosition));
		float x = xPosition / mag;
		float y = yPosition / mag;
		projectile = new Engine::Projectile(1, projectilePos, x, y, false);
		projectile->animator.Trigger("FireIce");
	}
}

void Wizard::OnCollisionEnter(Engine::Collider* other)
{
	if (state != DIE)
	{
		if (other->tag == "Spell")
		{
			if (state != HURT)
			{
				animator.Stop();
				animator.Trigger("Hurt");
				state = HURT;
			}
			hitpoint--;
		}
	}
}

void Wizard::OnCollisionExit(Engine::Collider* other)
{
	//isHurt = false;
}
