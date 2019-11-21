#include "Entity.h"
#include "Camera.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
namespace Engine 
{
	void Entity::AddCollider(std::string tag, bool _boxCollider)
	{
		if (_boxCollider) boxCollider = new BoxCollider(destRect, 0, tag, this);
		else  circleCollider = new CircleCollider(destRect, tag, this);
	}
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
		
		if (boxCollider || circleCollider)
		{
			if (boxCollider) {
				if (boxCollider->collisions.size() > 0)
				{
					for (auto col : boxCollider->collisions)
						OnCollisionEnter(col);
				}
				boxCollider->UpdateCollider(destRect, rotation);
			}
			else 
			{
				if (circleCollider->collisions.size() > 0)
				{
					for (auto col : circleCollider->collisions)
						OnCollisionEnter(col);
				}
				circleCollider->UpdateCollider(destRect, 0);
			}
		}
	}
	void Entity::Render()
	{
		if (texture)
		{
			destRect.x -= Engine::Camera::ActiveCamera->Position.X;
			destRect.y -= Engine::Camera::ActiveCamera->Position.Y;
			if (PlayAnimation)
			{
				animator.DisplayAnimation(destRect.x, destRect.y);
				animator.ChangeScale(ScaleX, ScaleY);
			}
			else
			{ Engine::TextureManager::Draw(texture, sourceRect, destRect, rotation); }
			
			
		}
	}
	void Entity::UpdateCollisionBox()
	{
		if (boxCollider)
		{
			boxCollider->UpdateCollider(destRect, rotation);
		}
		if (circleCollider) circleCollider->UpdateCollider(destRect, 0);
		destRect.x = position.X; destRect.y = position.Y;
	}
}
