#pragma once

#include "TextureManager.h"
#include <string>
#include <vector>

namespace Engine
{
	class Animation
	{
	public:
		Animation(const std::string _spritePath, std::string name, int _totalSpritesInRow, int _totalSpritesInColumn, int desPositionX, int desPositionY);
		~Animation();
		void AnimationSetup(const std::string _spritePath, int totalSpritesInOneRow, int totalSpritesInOneColumn, Vector2D desPosition);
		void PlayAnimation(int speed);
	
	private:
		std::string spritePath = "";
		int totalSpritesInRow = 0, totalSpritesInColumn;
		int textureWidth = 0, textureHeight = 0;
		int frameWidth = 0, frameHeight = 0;
		SDL_Rect src, des;
		const int framePerSecond = 60;
		int framtime = 0;
	};
}

