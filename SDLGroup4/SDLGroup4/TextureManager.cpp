#include "TextureManager.h"
#include "Window.h"

#include <SDL_render.h>
#include <SDL_image.h>
#include <iostream>


namespace Engine {

	Textures TextureManager::textures;
	void TextureManager::Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect)
	{
		if (sprite && Engine::Window::Renderer)
			SDL_RenderCopy(Engine::Window::Renderer, sprite, &srcRect, &desRect);
	}
	void TextureManager::Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect, float rotation, SDL_RendererFlip flip)
	{
		if(sprite && Engine::Window::Renderer) 
			SDL_RenderCopyEx(Engine::Window::Renderer, sprite, &srcRect, &desRect, rotation, nullptr, flip);
	}

	SDL_Texture* TextureManager::LoadTexture(const std::string& texturePath)
	{
		SDL_Surface* surface = IMG_Load(texturePath.c_str());
		if (!surface)
			std::cout << "Failed to create SDL_surface. SDL Error: " << SDL_GetError << std::endl;
		else
		{
			SDL_Texture* newTexture = SDL_CreateTextureFromSurface(Engine::Window::Renderer, surface);
			SDL_FreeSurface(surface);
			surface = nullptr;
			return newTexture;
		}

		return nullptr;
	}
	void TextureManager::AddTexture(std::string name, const std::string& _path)
	{
		if (!HasTexture(name))
		{
			SDL_Texture* texture = Engine::TextureManager::LoadTexture(_path);
			textures.insert({ name, texture });
		}
	}
	bool TextureManager::HasTexture(std::string name)
	{
		auto it = textures.find(name);
		if (it != textures.end()) {
			return true;
		}
		return false;
	}
	SDL_Texture* TextureManager::GetTexture(std::string name)
	{
		if (HasTexture(name)) 
		{ return textures.find(name)->second; }
		return nullptr;
	}
	void TextureManager::Shutdown()
	{
		for (auto it = textures.begin(); it != textures.end(); it++)
		{
			SDL_DestroyTexture(it->second);
		}
		textures.clear();
	}
}
