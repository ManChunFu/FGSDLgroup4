#pragma once
#include "Window.h"
#include <unordered_map>
#include <string>
#include <SDL_rect.h>

struct SDL_Texture;

	
namespace Engine
{
	typedef std::unordered_map<std::string, SDL_Texture*> Textures;
	class TextureManager
	{
	public:
		static void Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect);
		static void Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect, float rotation, /*SDL_Point pivot*/ SDL_RendererFlip flip);
		static void AddTexture(std::string name, const std::string& _path);
		static bool HasTexture(std::string name);
		static SDL_Texture* GetTexture(std::string name);
		static void Shutdown();
	private:
		static SDL_Texture* LoadTexture(const std::string& texturePath);
		static Textures textures;
	};
}

