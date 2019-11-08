#pragma once

#include <string>
#include "GameElement.h"

struct SDL_Texture;

namespace Engine
{
	class Image: public GameElement
	{
	public:
		Image(const std::string& imagePath, GameElement base);
		~Image();

		void Render() override;

	private:
		std::string imagePath;
		SDL_Texture* newImage;
	};
}

