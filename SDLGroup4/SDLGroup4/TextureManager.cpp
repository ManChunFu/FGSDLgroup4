#include "TextureManager.h"

#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_rect.h>
#include <iostream>

SDL_Texture* Engine::TextureManager::Texture = nullptr;

Engine::TextureManager::TextureManager(SDL_Renderer* renderer, int _width, int _height, int _xCoordinate, int _yCoordinate, const std::string& texture_path):
	width(_width), height(_height), xCoordinate(_xCoordinate), yCoordinate(_yCoordinate)
{
	SDL_Surface* surface = IMG_Load(texture_path.c_str());
	if (!surface)
		std::cout << "Failed to create SDL_surface. SDL Error: " << SDL_GetError << std::endl;
	else
		Texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (!Texture)
		std::cout << "Failed to create SDL_texture." << std::endl;

	SDL_FreeSurface(surface);

}

Engine::TextureManager::~TextureManager()
{
	if (Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}
}


void Engine::TextureManager::Draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = { xCoordinate, yCoordinate, width, height };

	if (Texture)
		SDL_RenderCopy(renderer, Texture, nullptr, &rect);
}

