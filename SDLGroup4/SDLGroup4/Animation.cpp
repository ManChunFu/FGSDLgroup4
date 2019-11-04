#include "Animation.h"

#include <iostream>

std::string Engine::Animation::spritePath = "";
int Engine::Animation::textureWidth = 0;
int Engine::Animation::textureHeight = 0;
int Engine::Animation::frameWidth = 0;
int Engine::Animation::frameHeight = 0;
SDL_Rect Engine::Animation::src;
SDL_Rect Engine::Animation::des;

int Engine::Animation::framtime = 0;

void Engine::Animation::AnimationSetup(const std::string _spritePath, int totalSpritesInOneRow, int totalSpritesInOneColumn, int desPositionX, int desPositionY)
{
	SDL_Texture* newAnimation;
	newAnimation = Engine::TextureManager::Texture(_spritePath);
	if (newAnimation == nullptr)
		std::cout << "Failed to load sprite. SDL Error: " << SDL_GetError << std::endl;
	else
	{
		spritePath = _spritePath;

		SDL_QueryTexture(newAnimation, nullptr, nullptr, &textureWidth, &textureHeight);

		frameWidth = textureWidth / totalSpritesInOneRow;
		frameHeight = textureHeight / totalSpritesInOneColumn;
		src.x = src.y = 0;
		src.w = frameWidth;
		src.h = frameHeight;
		des.x = desPositionX;
		des.y = desPositionY;
		des.w = frameWidth;
		des.h = frameHeight;
	}

	if (&src == nullptr || &des == nullptr)
		std::cout << "Failed to setup animated sprite's source / destination value. SDL Error: " << SDL_GetError << std::endl;
}

void Engine::Animation::PlayAnimation(int speed)
{
	framtime++;

	if (framePerSecond/framtime == speed)
	{
		framtime = 0;
		src.x += frameWidth;
		if (src.x >= textureWidth)
			src.x = 0;
	}

	Engine::Window::RenderClear();
	Engine::TextureManager::Draw(Engine::TextureManager::Texture(spritePath), src, des);
	Engine::Window::RenderPresent();

}

