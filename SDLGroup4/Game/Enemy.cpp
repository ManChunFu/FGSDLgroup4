#include "Enemy.h"
#include <InputManager.h>
#include <Vector2D.h>



Enemy::Enemy(std::string& spritePath, int width, int height, float xPos, float yPos)
{

}

void Enemy::Update()
{
	
}

void Enemy::MovePlayer(float deltaTime)
{
	Engine::Vector2D movement;
	if (inputManager->IsKeyDown(SDL_SCANCODE_A))
		movement.X = -1.0f;

	if (inputManager->IsKeyDown(SDL_SCANCODE_D))
		movement.X = 1.0f;

	if (inputManager->IsKeyDown(SDL_SCANCODE_W))
		movement.Y = -1.0f;

	if (inputManager->IsKeyDown(SDL_SCANCODE_S))
		movement.Y = 1.0f;

	//position += movement * speed * deltaTime;
}
