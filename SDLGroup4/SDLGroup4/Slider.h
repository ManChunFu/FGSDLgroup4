#pragma once
#include "GameElement.h"
#include <string>
#include <SDL_rect.h>
#include "TextureManager.h"
namespace Engine 
{
	class Slider : public GameElement
	{
	public:
		Slider(const std::string& spriteName, SDL_Color color, GameElement base);
		void Render() override;
		float amount = 1;
	private:
		SDL_Texture* texture;
		SDL_Rect sourceRect, destRect;
	};
}
