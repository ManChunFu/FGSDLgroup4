#pragma once

#include <string>
#include <SDL_rect.h>

struct SDL_Texture;
struct SDL_Color;
struct SDL_Renderer;

namespace Engine
{
	class Text
	{
	public:
		Text(SDL_Renderer* renderer, const std::string& font_path, int fontsize, const std::string& message_text, SDL_Color color);
	private:
		SDL_Texture* LoadFont(SDL_Renderer* renderer, const std::string& font_path, int fontsize, const std::string& message_text, SDL_Color color);

		SDL_Texture* textTexture;
		SDL_Rect textRect;
	};
}

