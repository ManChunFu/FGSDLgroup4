#include "Player.h"
#include<InputManager.h>
#include<TextureManager.h>
#include <GameTime.h>
#include<Vector2D.h>
#include<Projectile.h>
#include "TestBullet.h"


void Player::Update()
{

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
	if (inputManager->GetAxis("Fire") == 1) 
	{
		bullet = new Bullet(3, bulletpos); 
		bullet->AddSprite("Bullet");
	}

	Engine::Vector2D projectilePos;
	if (dirX == 0 && dirY == 0)
	{
		dirX = 1;
	}
	if (inputManager->GetAxis("Space")==1)
	{
		projectile = new Engine::Projectile(3, projectilePos, dirX, dirY);
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
