#include "Slider.h"

Engine::Slider::Slider(const std::string& spriteName, SDL_Color color, GameElement base)
{
	texture = Engine::TextureManager::GetTexture(spriteName);
	SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);
	destRect.w = sourceRect.w;
	destRect.h = sourceRect.h;
}

void Engine::Slider::Render()
{
	for (int i = 0; i < amount; i++)
	{
		SDL_Rect destinationRect = destRect;
		destinationRect.x += i * sourceRect.w;
		TextureManager::Draw(texture, sourceRect, destinationRect);
	}
}
