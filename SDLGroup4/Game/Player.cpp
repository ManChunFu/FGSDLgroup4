#include "Player.h"
#include<InputManager.h>
#include<TextureManager.h>
#include <Time.h>
#include<Vector2D.h>




void Player::Update()
{
	MovePlayer();
	Engine::Entity::Update();
}

void Player::Render()
{
	Engine::Entity::Render();
}


void Player::MovePlayer()
{
	Engine::Vector2D movement;
	if (inputManager->IsKeyDown(SDL_SCANCODE_UP))
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
	}

	posX += movement.X * moveSpeed *Engine::Time::DeltaTime();
	posY += movement.Y * moveSpeed * Engine::Time::DeltaTime();
}
