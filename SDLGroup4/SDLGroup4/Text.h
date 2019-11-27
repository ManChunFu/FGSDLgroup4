#pragma once
#include "Vector2D.h"
#include "GameElement.h"
#include <string>
#include <SDL_rect.h>


struct SDL_Texture;
struct SDL_Color;

namespace Engine
{
	class Text: public GameElement
	{
	public:
		Text(const std::string& fontPath, int fontsize, const std::string& messageText, SDL_Color color, GameElement base);//Engine::Vector2D position);
		~Text();

		void ChangeTextColor(SDL_Color * color);
		void Render() override;
		void UpdatePosition(float xCoordinate, float yCoordinate) override;
		SDL_Texture* LoadFont(const std::string& fontPath, int fontsize, const std::string& messageText, SDL_Color color);
		void Script(std::string& text);
	private:
		SDL_Texture* textTexture;
		SDL_Rect textRect;
		std::string fontPath, messageText;
		int fontsize;
		SDL_Color color;

	};
}

