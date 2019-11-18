#include "Player.h"
#include<InputManager.h>
#include<TextureManager.h>
#include <GameTime.h>
#include<Vector2D.h>
#include "TestBullet.h"


void Player::Update()
{
	MovePlayer();
	if (position.X < 0) position.X = 0;
	if (position.X > 1440 - destRect.w) position.X = 1440 - destRect.w;
	if (position.Y < 0) position.Y = 0;
	if (position.Y > 900 - destRect.h) position.Y = 900 - destRect.h;
	Engine::Entity::Update();
	
	Engine::Vector2D bulletpos;
	bulletpos.X = position.X;
	bulletpos.Y = position.Y;
	if (inputManager->GetAxis("Space") == 1) 
	{
		bullet = new Bullet(3, bulletpos); 
		bullet->AddSprite("FireSpell");
	}
}



void Player::MovePlayer()
{
	Engine::Vector2D movement;
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

	position.X += inputManager->GetAxis("Horizontal") * moveSpeed *Engine::GameTime::DeltaTime();
	position.Y += inputManager->GetAxis("Vertical") * moveSpeed * Engine::GameTime::DeltaTime();
}

void Player::OnCollisionEnter(Engine::Collider* other)
{
}
