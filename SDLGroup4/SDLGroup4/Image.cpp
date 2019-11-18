#include "Image.h"
#include "TextureManager.h"
#include <SDL_render.h>

Engine::Image::Image(const std::string& imagePath, GameElement base)
{
	width = base.width;
	height = base.height;
	xCoordinate = base.xCoordinate;
	yCoordinate = base.yCoordinate;

	newImage = Engine::TextureManager::GetTexture(imagePath);
}

Engine::Image::~Image()
{
	if (newImage != nullptr)
	{
		SDL_DestroyTexture(newImage);
		newImage = nullptr;
	}
}

void Engine::Image::Render()
{
	SDL_Rect srcRect = { 0, 0, width, height };
	SDL_Rect desRect = { xCoordinate, yCoordinate, width, height };

	Engine::TextureManager::Draw(newImage, srcRect, desRect);
}
