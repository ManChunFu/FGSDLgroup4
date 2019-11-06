#include "Animation.h"

#include <iostream>
namespace Engine {
	std::string Animation::spritePath = "";
	int Animation::textureWidth = 0;
	int Animation::textureHeight = 0;
	int Animation::frameWidth = 0;
	int Animation::frameHeight = 0;
	SDL_Rect Animation::src;
	SDL_Rect Animation::des;
	SDL_Texture* Animation::animationTexture;
	int Animation::framtime = 0;

	void Animation::AnimationSetup(const std::string _spritePath, int totalSpritesInOneRow, int totalSpritesInOneColumn, int desPositionX, int desPositionY)
	{
		SDL_Texture* newAnimation;
		newAnimation = Engine::TextureManager::Texture(_spritePath);
		animationTexture = newAnimation;
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

	void Animation::PlayAnimation(int speed)
	{
		framtime++;

		if (framePerSecond / framtime == speed)
		{
			framtime = 0;
			src.x += frameWidth;
			if (src.x >= textureWidth)
				src.x = 0;
		}
		Engine::TextureManager::Draw(animationTexture, src, des);
	}
}
