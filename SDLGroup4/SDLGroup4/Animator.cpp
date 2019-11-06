#include "Animator.h"

void Engine::Animator::Trigger(const std::string& name)
{
	for (auto animationClipID = 0; animationClipID < Animations.size(); animationClipID++)
	{
		if (Animations[animationClipID]->name == name.c_str())
		{
			currenAnimation = Animations[animationClipID];
			Animations.erase(Animations.begin() + animationClipID);
			isTrigger = true;
		}
	}

}

void Engine::Animator::Stop()
{
	isTrigger = false;
	Animations.push_back(currenAnimation);
	currenAnimation = nullptr;
}

void Engine::Animator::DisplayAnimation(int x, int y)//(Vector2D position)
{
	if (isTrigger)
		if (currenAnimation != nullptr)
			currenAnimation->PlayAnimation(x, y);//(position);
}
