#pragma once
#include "Collider.h"
#include "TextureManager.h"
#include <SDL_rect.h>
#include <SDL_image.h>
#include <string>
#include "EntityManager.h"
#include <iostream>
#include "Animator.h"
#include "Animation.h"
#include "Scene.h"
#include "Vector2D.h"
#include "AbstractionModule.h"
namespace Engine {
	class Entity {
	public:
		virtual ~Entity() {}
		Entity()
		{
			scene = AbstractionModule::ActiveScene;
			position = new Vector2D();
			position->X = 0;
			position->Y = 0;
			scene->EntityManager()->AddEntity(this);
		}
		void AddCollider(std::string tag){ collider = new Engine::Collider(destRect, tag, scene); }
		void AddSprite(std::string _path, int scaleX, int scaleY) 
		{ 
			texture = Engine::TextureManager::Texture(_path);  
			SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w, &sourceRect.h);
			destRect.w = sourceRect.w * scaleX;
			destRect.h = sourceRect.h * scaleY;
		};
		void AddSprite(std::string _path)
		{
			texture = Engine::TextureManager::Texture(_path);
			SDL_QueryTexture(texture, NULL, NULL, &sourceRect.w, &sourceRect.h);
			destRect.w = sourceRect.w;
			destRect.h = sourceRect.h;
		};
		virtual void Update() 
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
		void Render() 
		{ 
			/*std::cout << sourceRect.y << sourceRect.x << std::endl;*/ 
			if (texture)
			{
				Engine::TextureManager::Draw(texture, sourceRect, destRect);
				animator.DisplayAnimation(position->X, position->Y);
			}
		}

		Engine::Animator animator;

	protected:
		virtual void OnCollisionEnter(Engine::Collider* other) {}
		Vector2D* position = nullptr;
		Engine::Collider* collider = nullptr;
	private:
		SDL_Rect sourceRect;
		SDL_Rect destRect;
		SDL_Texture* texture = nullptr;
		Scene* scene = nullptr;
	};

}