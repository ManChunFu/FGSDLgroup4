#pragma once
#include "Window.h"

#include <string>
#include <SDL_rect.h>

struct SDL_Texture;

namespace Engine
{
	class TextureManager
	{
	public:
		static void Draw(SDL_Texture* sprite, SDL_Rect srcRect, SDL_Rect desRect);
		static SDL_Texture* Texture(const std::string& texturePath);
	};
}

