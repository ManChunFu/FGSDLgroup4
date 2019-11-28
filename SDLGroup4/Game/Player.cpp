#include "Player.h"
#include <InputManager.h>
#include <TextureManager.h>
#include <GameTime.h>
#include <Vector2D.h>
#include <Projectile.h>
#include "TimedExplosive.h"
#include "MainScene.h"
#include "Enemy.h"
#include <Application.h>
#include <SoundManager.h>
void Player::Update()
{
	if (mineTimer > 0) mineTimer -= Engine::GameTime::DeltaTime();
	collider->solid = true;
	currPos = position;
	dirX = inputManager->GetAxis("Horizontal");
	dirY = inputManager->GetAxis("Vertical");

	if (state != DIE)
	 MovePlayer(); 
	hpSlider->amount = hitPoint;
	if (position.X < 0) position.X = 0;
	if (position.X > 1440 - (destRect.w)) position.X = 1440 - destRect.w;
	if (position.Y < 0) position.Y = 0;
	if (position.Y > 900 - (destRect.h)) position.Y = 900 - destRect.h;
	Engine::Entity::Update();

	shootTimer += Engine::GameTime::DeltaTime();
	Shoot();

	if (damageTimer > 150.f)
	{
		hpLost = false;
		damageTimer = 0;
	}


	if (dirX != 0 || dirY != 0)
	{
		lastDirection.X = dirX;
		lastDirection.Y = dirY;
	}

	if (hitPoint < 1 && state != DIE)
	{
		animator.Stop();
		animator.Trigger("Die");
		state = DIE;
		isDead = true;
	}
	if (state == DIE && animator.CurrenAnimation->StopPlaying)
	{
		MainScene::ActiveScene->LoadScene(2);
	}
		
}


void Player::MovePlayer()
{
	if (teleportTimer > 0)
	{
		teleportTimer -= Engine::GameTime::DeltaTime();
		if (inputManager->IsKeyReleased(Key::SPACE)) hasTeleported = false;
	}
	moveSpeed = normalSpeed;
	if (teleportTimer <= 0 && !hasTeleported && inputManager->GetAxis("Space") != 0 && (dirX != 0 || dirY != 0))
	{
		teleportTimer = teleportCooldown;
		hasTeleported = true;
		moveSpeed = teleportDistance;
	}

	position.X += dirX * moveSpeed * Engine::GameTime::DeltaTime();
	position.Y += dirY * moveSpeed * Engine::GameTime::DeltaTime();


	if (animator.CurrenAnimation->RunFullClip)
		return;

	if (dirX == 0 && dirY == 0)
	{
			animator.Stop();
			animator.Trigger("Idle");
		if (state != IDLE)
		{
			state = IDLE;
		}
	}
	else
	{
		if (dirX > 0)
		{
			if (state != RUNRIGHT)
			animator.Stop();
			animator.Trigger("Run");
			spriteFlip = SDL_FLIP_NONE;
			state = RUNRIGHT;
		}
		else if (dirX < 0)
		{
			if (state != RUNLEFT)
			animator.Stop();
			animator.Trigger("Run");
			spriteFlip = SDL_FLIP_HORIZONTAL;
			state = RUNLEFT;
		}
		else
		{
			animator.Stop();
			animator.Trigger("Run");
		}
	}
}

void Player::Shoot()
{
	Engine::Vector2D bulletpos;
	bulletpos.X = position.X;
	bulletpos.Y = position.Y;
	if (inputManager->IsKeyPressed(Key::RETURN) && mineTimer < 0)
	{
		
		bullet = new TimedExplosive(3, bulletpos);
		mineTimer = mineCooldown;
	}

	Engine::Vector2D projectilePos;
	projectilePos.X += position.X + (55.f * lastDirection.X);
	projectilePos.Y += position.Y + (60.f * lastDirection.Y);

	if (inputManager->GetAxis("Fire2") == 1)
	{
		if (state != ATTACK)
		{
			animator.Stop();
			animator.Trigger("Attack");
			state = ATTACK;
			if (state == ATTACK && dirX > 0)
				spriteFlip = SDL_FLIP_NONE;
			else if(state == ATTACK && dirX < 0)
				spriteFlip = SDL_FLIP_HORIZONTAL;
		}

		if (shootTimer > 0.4f)
		{
			shootTimer = 0;
			projectile = new Engine::Projectile(3, projectilePos, lastDirection.X, lastDirection.Y, true);
			Engine::SoundManager::PlaySoundEffect("Shoot", 0, 10);
			if (lastDirection.Y != 0)
			{
				projectile->position.X = position.X + 20.f;
				
			}
			else
			{ projectile->position.Y = position.Y + 15.f; }
				projectile->animator.Trigger("FireIce");
		}
	}
}

void Player::OnCollisionExit(Engine::Collider* other)
{
	collider->solid = true;
}

void Player::OnCollisionEnter(Engine::Collider* other)
{
	damageTimer++;
	if (state != DIE)
	{
		if (other->tag == "EnemySpell") hitPoint--;
		if (other->tag == "Enemy")
		{
			Enemy* enemy = dynamic_cast<Enemy*>(other->GameObject);
			collider->solid = false;
			if (enemy->Attack)
			{
				if (state != HURT)
				{
					animator.Stop();
					animator.Trigger("Hurt");
					state = HURT;
				}
				if (!hpLost)
				{
					hitPoint--;
					Engine::SoundManager::PlaySoundEffect("Hurt", 0, 10);
					hpLost = true;
				}
			}
		}
	}
}
