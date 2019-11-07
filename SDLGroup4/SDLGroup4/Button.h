#pragma once

#include "GameElement.h"
#include <string>

namespace Engine
{
	class Button: public GameElement
	{
	public:
		Button(const std::string& text, GameElement base)
		{
			width = base.width; 
			height = base.height; 
			xCoordinate = base.xCoordinate; 
			yCoordinate = base.yCoordinate;
		};
		 
	private:
		std::string text;
		
	};
}

