#pragma once
#include "Vector2D.h"

#include <string>
#include <SDL_rect.h>

struct SDL_Texture;
struct SDL_Color;

namespace Engine
{
	class Text
	{
	public:
		Text(const std::string& font_path, int fontsize, const std::string& message_text, SDL_Color color, int x, int y);//Engine::Vector2D position);

		void DisplayText();
		SDL_Texture* LoadFont(const std::string& font_path, int fontsize, const std::string& message_text, SDL_Color color);
	private:
		SDL_Texture* textTexture;
		SDL_Rect textRect;
	};
}

