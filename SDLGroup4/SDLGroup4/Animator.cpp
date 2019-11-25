#include "Animator.h"

void Engine::Animator::Trigger(const std::string& name)
{	
	for (unsigned int animationClipID = 0; animationClipID < Animations.size(); animationClipID++)
	{
		if (Animations[animationClipID]->name == name.c_str())
		{			
			CurrenAnimation = Animations[animationClipID];
			CurrenAnimation->StopPlaying = false;
			Animations.erase(Animations.begin() + animationClipID);
			isTrigger = true;
			if (!CurrenAnimation->RunFullClip)
				BaseAnimation = name;
			return;
		}
	}
}

void Engine::Animator::Stop()
{
	isTrigger = false;
	Animations.push_back(CurrenAnimation);
	CurrenAnimation = nullptr;
}

void Engine::Animator::DisplayAnimation(Vector2D position, SDL_RendererFlip flip)
{
	if (isTrigger)
	{
		if (CurrenAnimation != nullptr)
		{
			if (CurrenAnimation->StopPlaying && BaseAnimation != "")
			{
				Stop();
				Trigger(BaseAnimation);				
			}
			CurrenAnimation->PlayAnimation(position, flip);
		}
	}
}

void Engine::Animator::ChangeScale(float amount)
{
	if(CurrenAnimation) CurrenAnimation->ChangeScale(amount);
}

void Engine::Animator::ChangeScale(float x, float y)
{
	if(CurrenAnimation) CurrenAnimation->ChangeScale(x, y);
}
