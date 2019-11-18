#include "Entity.h"
namespace Engine 
{
	void Entity::AddSprite(std::string _path, int scaleX, int scaleY)
	{
		texture = Engine::TextureManager::Texture(_path);
		SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w, &sourceRect.h);
		destRect.w = sourceRect.w * scaleX;
		destRect.h = sourceRect.h * scaleY;
	}
	void Entity::AddSprite(std::string _path)
	{
		texture = Engine::TextureManager::Texture(_path);
		SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w, &sourceRect.h);
		destRect.w = sourceRect.w;
		destRect.h = sourceRect.h;
	}
	void Entity::Update()
	{
		if (collider)
		{
			if (collider->collisions.size() > 0)
			{
				for (auto col : collider->collisions)
					OnCollisionEnter(col);
			}
			collider->UpdateBorders(destRect);
		}
		destRect.x = position->X; destRect.y = position->Y;
	}
	void Entity::Render()
	{
		if (texture)
		{
			Engine::TextureManager::Draw(texture, sourceRect, destRect);
			animator.DisplayAnimation(position->X, position->Y);
		}
	}
}
