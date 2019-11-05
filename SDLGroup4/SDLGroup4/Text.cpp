#include "Text.h"
#include "Window.h"

#include <SDL_ttf.h>
#include <iostream>


SDL_Texture* Engine::Text::ChooseFont(const std::string& font_path, int fontsize)
{
	auto font = TTF_OpenFont(font_path.c_str(), fontsize);
	if (!font)
		std::cout << "Failed to load font. SDL_Error: " << SDL_GetError << std::endl;
	else
	{
		//auto fontTexture = SDL_CreateTexture(Engine::Window::Renderer, NULL, NULL)
	}
	return nullptr;
}
