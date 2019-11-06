#pragma once

#include <string>
struct SDL_Texture;
struct SDL_Color;
struct SDL_Rect;

namespace Engine
{
	class Text
	{
	public:

	private:
		SDL_Texture* ChooseFont(const std::string& font_path, int fontsize);

		SDL_Texture* fontTexture;
		//SDL_Rect textRect;
	};
}

