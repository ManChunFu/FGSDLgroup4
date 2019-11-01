#include "TextureManager.h"
#include "TextureManager.h"
#include "Window.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>



void Engine::TextureManager::Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect)
{
	SDL_RenderCopy(Engine::Window::Renderer, sprite, &srcRect, &desRect);
}

SDL_Texture* Engine::TextureManager::Texture(const std::string& texture_path)
{
	SDL_Surface* surface = IMG_Load(texture_path.c_str());
	if (!surface)
		std::cout << "Failed to create SDL_surface. SDL Error: " << SDL_GetError << std::endl;
	else
	{
		SDL_FreeSurface(surface);
		surface = nullptr;
		return SDL_CreateTextureFromSurface(Engine::Window::Renderer, surface);
	}

	return nullptr;
}

