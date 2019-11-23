#include "Entity.h"
#include "Camera.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
namespace Engine 
{
	void Entity::AddCollider(std::string tag, bool _boxCollider)
	{
		if (!collider) 
		{
			if (_boxCollider) collider = new BoxCollider(destRect, 0, tag, this);
			else  collider = new CircleCollider(destRect, tag, this);
		}
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
		
		if (collider)
		{
				if (collider->collisions.size() > 0)
				{
					for (auto col : collider->collisions)
						OnCollisionEnter(col);
				}
				collider->UpdateCollider(destRect, rotation);
			
		}
		lastPosition = position;
	}
	void Entity::Render()
	{
		if (texture)
		{
			position.X -= Engine::Camera::ActiveCamera->Position.X;
			position.Y -= Engine::Camera::ActiveCamera->Position.Y;
			UpdateCollisionBox();
			if (PlayAnimation)
			{
				animator.DisplayAnimation(position, spriteFlip);
				//animator.ChangeScale(ScaleX, ScaleY);
			}
			else
			{ Engine::TextureManager::Draw(texture, sourceRect, destRect, rotation, spriteFlip); }
			
			
		}
	}
	void Entity::UpdateCollisionBox()
	{
		if(collider) collider->UpdateCollider(destRect, rotation);
		destRect.x = position.X; destRect.y = position.Y;
	}
}
