#include "Animation.h"

#include <iostream>


Engine::Animation::Animation(const std::string spritePath, std::string name, int spriteSheetLenghtX, int spriteSheetLengthY, int speed) :
	spritePath(spritePath), name(name.c_str()), speed(speed)
{
	newAnimation = Engine::TextureManager::GetTexture(spritePath);
	
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


void Engine::Animation::PlayAnimation(Vector2D& position)
{
	framtime++;
	destinationRect.x =position.X;
	destinationRect.y =position.Y;

	if (framePerSecond/framtime == speed)
	{
		framtime = 0;
		sourceRect.x += frameWidth;
		if (sourceRect.x >= spriteWidth)
			sourceRect.x = 0;
	}
	
	Engine::TextureManager::Draw(newAnimation, sourceRect, destinationRect, 0);
}

void Engine::Animation::ChangeScale(float amount)
{
	destinationRect.w = sourceRect.w * amount;
	destinationRect.h = sourceRect.h * amount;
}

void Engine::Animation::ChangeScale(float x, float y)
{
	destinationRect.w = sourceRect.w * x;
	destinationRect.h = sourceRect.h * y;
}

