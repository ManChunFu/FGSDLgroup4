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

		void Trigger(const std::string& name);
		void Stop();
		void DisplayAnimation(float x, float y);//(Vector2D position);

		std::vector<Animation*> Animations;
		Animation* currenAnimation = nullptr;
		bool isTrigger;
	};
}

