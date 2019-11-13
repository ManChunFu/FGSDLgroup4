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
namespace Engine {
	class Entity {
	public:
		virtual ~Entity() {}
		Entity(std::string path, int height, int width, int xpos, int ypos, Scene* scene)
		{
			posX = xpos;
			posY = ypos;
			sourceRect.w = width;
			sourceRect.h = height;
			sourceRect.x = 0;
			sourceRect.y = 0;
			destRect.w = width;
			destRect.h = height;
			destRect.x = posX;
			destRect.y = posY;
			texture = TextureManager::Texture(path);
			collider = new Engine::Collider(destRect, "something", scene);
			scene->EntityManager()->AddEntity(this);

		}

		virtual void Update() { destRect.x = posX; destRect.y = posY; collider->UpdateBorders(destRect); }
		virtual void Render() 
		{ 
			/*std::cout << sourceRect.y << sourceRect.x << std::endl;*/ 
			Engine::TextureManager::Draw(texture, sourceRect, destRect);

			animator.DisplayAnimation(posX, posY);
		}

		Engine::Animator animator;

	protected:
		float posX;
		float posY;
		Engine::Collider* collider;
		SDL_Rect sourceRect;
		SDL_Rect destRect;
		SDL_Texture* texture;

	};
}