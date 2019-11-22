#include "Animator.h"

void Engine::Animator::Trigger(const std::string& name)
{	
	for (unsigned int animationClipID = 0; animationClipID < Animations.size(); animationClipID++)
	{
		if (Animations[animationClipID]->name == name.c_str())
		{			
			currenAnimation = Animations[animationClipID];
			currenAnimation->stopPlaying = false;
			Animations.erase(Animations.begin() + animationClipID);
			isTrigger = true;
			if (!currenAnimation->runFullClip)
				baseAnimation = name;
		}
	}
}

void Engine::Animator::Stop()
{
	isTrigger = false;
	Animations.push_back(currenAnimation);
	currenAnimation = nullptr;
}

void Engine::Animator::DisplayAnimation(Vector2D position, SDL_RendererFlip flip)
{
	if (isTrigger)
	{
		if (currenAnimation != nullptr)
		{
			if (currenAnimation->stopPlaying)
			{
				Stop();
				Trigger(baseAnimation);
				return;
			}

			currenAnimation->PlayAnimation(position, flip);
		}
	}
}

void Engine::Animator::ChangeScale(float amount)
{
	if(currenAnimation) currenAnimation->ChangeScale(amount);
}

void Engine::Animator::ChangeScale(float x, float y)
{
	if(currenAnimation) currenAnimation->ChangeScale(x, y);
}
