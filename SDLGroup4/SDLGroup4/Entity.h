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
		virtual ~Entity() {}
		Entity(std::string path, float scale, int xpos, int ypos)
		{
			int width;
			int height;
			texture = TextureManager::Texture(path);
			SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
			posX = xpos;
			posY = ypos;
			sourceRect.x = 0;
			sourceRect.y = 0;
			destRect.w = width * scale;
			destRect.h = height * scale;
			destRect.x = posX;
			destRect.y = posY;
			sourceRect.w = width;
			sourceRect.h = height;
			collider = new Engine::Collider(destRect, "Player", TextureManager::Surface(path), scale);
			Engine::EntityManager::AddEntity(this);

			//testing animation
			//animator.Animations.push_back(new Animation("Assets/Sprites/x64testing.png", "Run", 6, 1, 5));
			//animator.Trigger("Run");

		}

		virtual void Update() { destRect.x = posX; destRect.y = posY; collider->UpdateBorders(destRect); }
		virtual void Render() 
		{ 
			/*std::cout << sourceRect.y << sourceRect.x << std::endl;*/ 
			Engine::TextureManager::Draw(texture, sourceRect, destRect);

			//animator.DisplayAnimation(posX, posY);
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