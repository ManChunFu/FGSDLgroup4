#include "Entity.h"
#include "Camera.h"
namespace Engine 
{
	void Entity::AddSprite(std::string _name, float scaleX, float scaleY)
	{
		texture = Engine::TextureManager::GetTexture(_name);
		SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);
		destRect.w = sourceRect.w * scaleX;
		destRect.h = sourceRect.h * scaleY;
		ScaleX = scaleX;
		ScaleY = scaleY;
	}
	void Entity::AddSprite(std::string _name)
	{
		texture = Engine::TextureManager::GetTexture(_name);
		SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);
		destRect.w = sourceRect.w;
		destRect.h = sourceRect.h;
	}
	void Entity::Update()
	{
		destRect.x = position.X; destRect.y = position.Y;
		destRect.w = ScaleX * sourceRect.w;
		destRect.h = ScaleY * sourceRect.h;
		if (collider)
		{
			if (collider->collisions.size() > 0)
			{
				for (auto col : collider->collisions)
					OnCollisionEnter(col);
			}
			collider->UpdateBorders(destRect);
		}
	}
	void Entity::Render()
	{
		if (texture)
		{
			destRect.x -= Engine::Camera::ActiveCamera->Position.X;
			destRect.y -= Engine::Camera::ActiveCamera->Position.Y;
			if (PlayAnimation) 
			{ animator.DisplayAnimation(destRect.x, destRect.y); }
			else
			{ Engine::TextureManager::Draw(texture, sourceRect, destRect); }
			
			
		}
	}
	void Entity::UpdateCollisionBox()
	{
		if (collider)
		{
			collider->UpdateBorders(destRect);
		}
		destRect.x = position.X; destRect.y = position.Y;
	}
}
