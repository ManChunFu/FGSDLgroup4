#include "Player.h"
#include<InputManager.h>

Player::Player(std::string path, int height, int width, int xpos, int ypos)
{
	player = new Entity(path, height, width, xpos, ypos);
}

void Player::Update()
{
	MovePlayer();
}

void Player::Render()
{
}


void Player::MovePlayer()
{
	if (inputManager->IsKeyPressed(SDL_SCANCODE_UP))
	{

	}
	if (inputManager->IsKeyPressed(SDL_SCANCODE_DOWN))
	{

	}
	if (inputManager->IsKeyPressed(SDL_SCANCODE_RIGHT))
	{

	}
	if (inputManager->IsKeyPressed(SDL_SCANCODE_LEFT))
	{

	}
}
