#pragma once

#include "GameElement.h"
#include "Text.h"
#include "Image.h"
#include "Button.h"
#include <vector>

struct SDL_Color;

namespace Engine
{
	class Canvas: public GameElement
	{
	public:
		Canvas(SDL_Color color, GameElement base)
		{
			width = base.width;
			height = base.height;
			xCoordinate = base.xCoordinate;
			yCoordinate = base.yCoordinate;
			Color = color;
		}
		void Render() override;

		void AddChild(GameElement* elemet);

		std::vector<GameElement*> Children;
		
		SDL_Color Color;

	};
}

