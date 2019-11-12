#include "Text.h"
#include "Window.h"
#include "TextureManager.h"

#include <SDL_ttf.h>
#include <iostream>

Engine::Text::Text(const std::string& font_path, int fontsize, const std::string& message_text, SDL_Color color, GameElement base)//Engine::Vector2D position)
{
	textTexture = LoadFont(font_path, fontsize, message_text, color);
	SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);

	this->xCoordinate =	textRect.x = base.xCoordinate ;//position.X;
	this->yCoordinate = textRect.y = base.yCoordinate;//position.Y;
}

Engine::Text::~Text()
{
	if (textTexture) { SDL_DestroyTexture(textTexture); }
	textTexture = nullptr;
}

void Engine::Text::Render()
{
	SDL_RenderCopy(Engine::Window::Renderer, textTexture, nullptr, &textRect);
}

void Engine::Text::UpdatePosition(float xCoordinate, float yCoordinate)
{
	textRect.x = this->xCoordinate = xCoordinate;
	textRect.y = this->yCoordinate = yCoordinate;
}

SDL_Texture* Engine::Text::LoadFont(const std::string& font_path, int fontsize, const std::string& message_text, SDL_Color color)
{
	TTF_Font* font = TTF_OpenFont(font_path.c_str(), fontsize);
	if (!font)
	{
		std::cout << "Failed to load font. SDL Error: " << SDL_GetError << std::endl;
		return nullptr;
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, message_text.c_str(), color);
	if (!textSurface)
		std::cout << "Failed to create text_surface." << SDL_GetError << std::endl;

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Engine::Window::Renderer, textSurface);
	if (!textTexture)
		std::cout << "Failed to create text_texture." << SDL_GetError << std::endl;
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);

	return textTexture;
}
