#pragma once
#include "Vector2D.h"

#include <string>
#include <SDL_rect.h>
#include "GameElement.h"

struct SDL_Texture;
struct SDL_Color;

namespace Engine
{
	class Text: public GameElement
	{
	public:
		Text(const std::string& font_path, int fontsize, const std::string& message_text, SDL_Color color, GameElement base);//Engine::Vector2D position);
		
		void ChangeTextColor(SDL_Color color);
		void Render() override;
		void UpdatePosition(float xCoordinate, float yCoordinate) override;
		SDL_Texture* LoadFont(const std::string& font_path, int fontsize, const std::string& message_text, SDL_Color color);
	private:
		SDL_Texture* textTexture;
		SDL_Rect textRect;
	};
}

