#pragma once
#include "Animation.h"
#include <vector>

namespace Engine
{
	class Animator
	{
	public:
		Animator(std::vector<Animation*> animations) { Animations = animations; }
		Animator() {}
		~Animator() { Animations.clear(); }

		static std::vector<Animation*> Animations;

		Animation* currenAnimation = nullptr;

	};
}

