#include "Player.h"
#include<InputManager.h>
#include<TextureManager.h>
#include <GameTime.h>
#include<Vector2D.h>
#include<Projectile.h>
#include "TimedExplosive.h"


void Player::Update()
{
	if (mineTimer > 0) mineTimer -= Engine::GameTime::DeltaTime();
	currPos = position;
	dirX = inputManager->GetAxis("Horizontal");
	dirY = inputManager->GetAxis("Vertical");

	MovePlayer();
	if (position.X < 0) position.X = 0;
	if (position.X > 1440 - destRect.w) position.X = 1440 - destRect.w;
	if (position.Y < 0) position.Y = 0;
	if (position.Y > 900 - destRect.h) position.Y = 900 - destRect.h;
	Engine::Entity::Update();
	
	Engine::Vector2D bulletpos;
	bulletpos.X = position.X;
	bulletpos.Y = position.Y;
	if (inputManager->IsKeyPressed(Key::RETURN) && mineTimer < 0) 
	{
		bullet = new TimedExplosive(3, bulletpos); 
		mineTimer = mineCooldown;
	}

	Engine::Vector2D projectilePos;
	projectilePos.X +=  position.X  + 100.f;
	projectilePos.Y +=  position.Y + 100.f;

	if (dirX == 0 && dirY == 0)
	{
		dirX = 1;
	}
	if (inputManager->GetAxis("Fire2")==1)
	{
		projectile = new Engine::Projectile(3,position, dirX, dirY);
		projectile->AddSprite("Projectile1");
	}


}



void Player::MovePlayer()
{
	
	/*if (inputManager->IsKeyDown(SDL_SCANCODE_UP))
	{
		movement.Y = -10.0f;
	}
	if (inputManager->IsKeyDown(SDL_SCANCODE_DOWN))
	{
		movement.Y = 10.0f;
	}
	if (inputManager->IsKeyDown(SDL_SCANCODE_RIGHT))
	{
		movement.X = 10.0f;
	}
	if (inputManager->IsKeyDown(SDL_SCANCODE_LEFT))
	{
		movement.X = -10.0f;
	}*/

	position.X +=dirX * moveSpeed *Engine::GameTime::DeltaTime();
	position.Y +=dirY * moveSpeed * Engine::GameTime::DeltaTime();
}

void Player::OnCollisionEnter(Engine::Collider* other)
{
}
