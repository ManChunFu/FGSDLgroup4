#include "Player.h"
#include<InputManager.h>
#include<TextureManager.h>
#include <Time.h>
#include<Vector2D.h>




void Player::Update()
{
	MovePlayer();
	if (position->X < 0) position->X = 0;
	if (position->X > 1440 - destRect.w) position->X = 1440 - destRect.w;
	if (position->Y < 0) position->Y = 0;
	if (position->Y > 900 - destRect.h) position->Y = 900 - destRect.h;
	Engine::Entity::Update();
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

	position->X += inputManager->GetAxis("Horizontal") * moveSpeed *Engine::Time::DeltaTime();
	position->Y += inputManager->GetAxis("Vertical") * moveSpeed * Engine::Time::DeltaTime();
}

void Player::OnCollisionEnter(Engine::Collider* other)
{
}
