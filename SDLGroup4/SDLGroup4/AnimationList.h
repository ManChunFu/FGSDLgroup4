#pragma once

#include <string>

namespace Engine
{
	class AnimationList
	{
	public:
		AnimationList(const std::string _spritePath, int totalSpritesInOneRow, int totalSpritesInOneColumn, int desPositionX, int desPositionY);
	};
}
