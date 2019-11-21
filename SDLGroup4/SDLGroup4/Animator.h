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
		void DisplayAnimation(Vector2D position);
		void ChangeScale(float amount);
		void ChangeScale(float x, float y);
		std::vector<Animation*> Animations;
		Animation* currenAnimation = nullptr;
		bool isTrigger;
	};
}

