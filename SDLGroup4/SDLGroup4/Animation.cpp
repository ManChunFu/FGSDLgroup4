#include "Animation.h"

#include <iostream>
#include "Vector2D.h"


Engine::Animation::Animation(const std::string spritePath, std::string name, int spriteSheetLenghtX, int spriteSheetLengthY, int speed) :
	spritePath(spritePath), name(name), speed(speed)
{
	SDL_Texture* newAnimation;
	newAnimation = Engine::TextureManager::Texture(spritePath);
	
	SDL_QueryTexture(newAnimation, nullptr, nullptr, &spriteWidth, &spriteHeight);

	frameWidth = spriteWidth / spriteSheetLenghtX;
	frameHeight = spriteHeight / spriteSheetLengthY;
	sourceRect.x = sourceRect.y = 0;
	sourceRect.w = destinationRect.w = frameWidth;
	sourceRect.h = destinationRect.h = frameHeight;

	if (&sourceRect == nullptr || &destinationRect == nullptr)
		std::cout << "Failed to setup animated sprite's source / destination value. SDL Error: " << SDL_GetError << std::endl;
}

Engine::Animation::~Animation()
{
}


void Engine::Animation::PlayAnimation(Vector2D position)
{
	framtime++;
	destinationRect.x = position.X;
	destinationRect.y = position.Y;

	if (framePerSecond/framtime == speed)
	{
		framtime = 0;
		sourceRect.x += frameWidth;
		if (sourceRect.x >= spriteWidth)
			sourceRect.x = 0;
	}

	Engine::TextureManager::Draw(Engine::TextureManager::Texture(spritePath), sourceRect, destinationRect);
}

