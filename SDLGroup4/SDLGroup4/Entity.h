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
		Entity(std::string path, int height, int width, int xpos, int ypos)
		{
			posX = xpos;
			posY = ypos;
			sourceRect.w = width;
			sourceRect.h = height;
			sourceRect.x = 0;
			sourceRect.y = 0;
			destRect.w = width;
			destRect.h = height;
			destRect.w = posX;
			destRect.w = posY;
			texture = TextureManager::Texture(path);
			collider = new Engine::Collider(destRect, "Player");
			Engine::EntityManager::AddEntity(this);

			/*animator.Animations =
			{
				new Engine::Animation("dsfds","Left",123,12,12,12),
				new Engine::Animation("dsfds","Right",123,12,12,12),
				new Engine::Animation("dsfds","Jump",12332,12,12,12)
			};*/
		}
		virtual void Update() { destRect.x = posX; destRect.y = posY; collider->UpdateBorders(destRect); }
		void Render() { /*std::cout << sourceRect.y << sourceRect.x << std::endl;*/ Engine::TextureManager::Draw(texture, sourceRect, destRect); }
	protected:
		float posX;
		float posY;
		Engine::Collider* collider;
		SDL_Rect sourceRect;
		SDL_Rect destRect;
		SDL_Texture* texture;
		/*Engine::Animator animator;*/
		
	};
}