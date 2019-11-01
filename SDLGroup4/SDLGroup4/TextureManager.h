#pragma once
#include "Window.h"
#include <string>

struct SDL_Renderer;
struct SDL_Texture;

namespace Engine
{
	class TextureManager
	{
		TextureManager(SDL_Renderer* renderer, int _width, int _height, int _xCoordinate, int _yCoordinate, const std::string& texture_path);
		~TextureManager();

	public: 
		void Draw(SDL_Renderer* renderer);
		

		static SDL_Texture* Texture;
	private:
		int width, height;
		int xCoordinate, yCoordinate;

	};
}

