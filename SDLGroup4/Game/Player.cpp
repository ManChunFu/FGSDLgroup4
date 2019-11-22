#include "Player.h"
#include<InputManager.h>
#include<TextureManager.h>
#include <GameTime.h>
#include<Vector2D.h>
#include<Projectile.h>
#include "TimedExplosive.h"

void Player::Update()
{
	rotation = 100;
	if (mineTimer > 0) mineTimer -= Engine::GameTime::DeltaTime();
	currPos = position;
	dirX = inputManager->GetAxis("Horizontal");
	dirY = inputManager->GetAxis("Vertical");

	MovePlayer();
	if (position.X < 0) position.X = 0;
	if (position.X > 1440 - (destRect.w)) position.X = 1440 - destRect.w;
	if (position.Y < 0) position.Y = 0;
	if (position.Y > 900 - (destRect.h)) position.Y = 900 - destRect.h;
	Engine::Entity::Update();

	shootTimer += Engine::GameTime::DeltaTime();
	Shoot();

	if (dirX != 0 || dirY != 0)
	{
		lastDirection.X = dirX;
		lastDirection.Y = dirY;
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
	if (teleportTimer <= 0 && !hasTeleported && inputManager->GetAxis("Space") != 0)
	{
		teleportTimer = teleportCooldown;
		hasTeleported = true;
		moveSpeed = teleportDistance;
	}

	position.X += dirX * moveSpeed * Engine::GameTime::DeltaTime();
	position.Y += dirY * moveSpeed * Engine::GameTime::DeltaTime();

	if (!isAttacking)
	{
		if (dirX == 0 && dirY == 0)
		{
			animator.Stop();
			animator.Trigger("Idle");

		}
		else
		{
			if (dirX > 0)
			{
				animator.Stop();
				animator.Trigger("Run");
				spriteFlip = SDL_FLIP_NONE;
			}
			else if (dirX < 0)
			{

				animator.Stop();
				animator.Trigger("Run");
				spriteFlip = SDL_FLIP_HORIZONTAL;
			}
			else
			{
				animator.Stop();
				animator.Trigger("Run");
			}
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
	projectilePos.X += position.X + (40.f * lastDirection.X);
	projectilePos.Y += position.Y + (40.f * lastDirection.Y);

	if (inputManager->GetAxis("Fire2") == 1)
	{
		animator.Stop();
		animator.Trigger("Attack");
		isAttacking = true;

		if (shootTimer > 0.5f)
		{
			isAttacking = false;
			shootTimer = 0;
			projectile = new Engine::Projectile(3, projectilePos, lastDirection.X, lastDirection.Y);
			if (lastDirection.Y != 0)
			{
				projectile->animator.Trigger("FireIce");
			}
			else
			{
				projectile->animator.Trigger("Firefire");
			}
		}
	}
}

void Player::OnCollisionEnter(Engine::Collider* other)
{
}
