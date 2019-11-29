#include "Slider.h"

Engine::Slider::Slider(const std::string& spriteName, SDL_Color color, GameElement base)
{
	texture = Engine::TextureManager::GetTexture(spriteName);
	SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);
	destRect.w = sourceRect.w;
	destRect.h = sourceRect.h;
	destRect.x = base.xCoordinate;
	destRect.y = base.yCoordinate;
}

void Engine::Slider::Render()
{
	destRect.w = sourceRect.w * scaleX;
	destRect.h = sourceRect.h * scaleY;
	for (int i = 0; i < amount; i++)
	{
		SDL_Rect destinationRect = destRect;
		destinationRect.x += i * destRect.w;
		TextureManager::Draw(texture, sourceRect, destinationRect);
	}
}
