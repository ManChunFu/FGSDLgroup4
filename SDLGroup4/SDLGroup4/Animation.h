#pragma once

#include "TextureManager.h"
#include <string>

namespace Engine
{
	class Animation
	{
	public:
		static void AnimationSetup(const std::string _spritePath, int totalSpritesInOneRow, int totalSpritesInOneColumn, int desPositionX, int desPositionY);
		static void PlayAnimation(int speed);
	
	private:
		static std::string spritePath;
		static int textureWidth, textureHeight;
		static int frameWidth, frameHeight;
		static SDL_Rect src, des;
		static const int framePerSecond = 60;
		static int framtime;
	};
}

