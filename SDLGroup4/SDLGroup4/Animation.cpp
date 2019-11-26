#include "Animation.h"

#include <iostream>


Engine::Animation::Animation(const std::string& _spritePath, const std::string& _name, int _spriteSheetLenghtX, int _spriteSheetLengthY, int _speed, bool _runFullClip, SDL_Rect _originSprite) :
	spritePath(_spritePath), name(_name.c_str()), speed(_speed), RunFullClip(_runFullClip)
{
	newAnimation = Engine::TextureManager::GetTexture(spritePath);
	originSprite = _originSprite;
	SDL_QueryTexture(newAnimation, nullptr, nullptr, &spriteWidth, &spriteHeight);

	frameWidth = spriteWidth / _spriteSheetLenghtX;
	frameHeight = spriteHeight / _spriteSheetLengthY;
	sourceRect.x = sourceRect.y = 0;
	sourceRect.w = destinationRect.w = frameWidth;
	sourceRect.h = destinationRect.h = frameHeight;

	if (&sourceRect == nullptr || &destinationRect == nullptr)
		std::cout << "Failed to setup animated sprite's source / destination value. SDL Error: " << SDL_GetError << std::endl;
}


void Engine::Animation::PlayAnimation(Vector2D& position, SDL_RendererFlip flip)
{
	framtime++;
	destinationRect.x = position.X;
	destinationRect.y = position.Y;
	if (destinationRect.h > originSprite.h)
		destinationRect.y -= destinationRect.h - originSprite.h;
	if (framePerSecond / framtime == speed)
	{
		framtime = 0;
		sourceRect.x += frameWidth;
		if (sourceRect.x >= spriteWidth)
		{
			sourceRect.x = 0;
			if (RunFullClip)
				StopPlaying = true;
		}
	}
	
	Engine::TextureManager::Draw(newAnimation, sourceRect, destinationRect, 0, flip);
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

