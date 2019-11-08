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

namespace Engine {
	class Entity {
	public:
		virtual ~Entity() {};
		Entity(std::string path, int height, int width, int xpos, int ypos, std::string name)
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
			collider = new Engine::Collider(destRect, name, TextureManager::Surface(path));
			Engine::EntityManager::AddEntity(this);
			
			//testing animation
			animator.Animations =
			{
				new Engine::Animation("Assets/Sprites/x64testing.png", "Run", 6, 1, 5)
			};
		}
		virtual void Update() { destRect.x = posX; destRect.y = posY; collider->UpdateBorders(destRect); }
		void Render() 
		{ 
			/*std::cout << sourceRect.y << sourceRect.x << std::endl;*/ 
			Engine::TextureManager::Draw(texture, sourceRect, destRect);

			//testing animation
			animator.Trigger("Run");
			if (animator.isTrigger)
				animator.DisplayAnimation(0, 0);
		}
	protected:
		float posX;
		float posY;
		Engine::Collider* collider;
		SDL_Rect sourceRect;
		SDL_Rect destRect;
		SDL_Texture* texture;
		Engine::Animator animator;

	};
}