#pragma once
#include "Collider.h"
#include "TextureManager.h"
#include <SDL_rect.h>
#include <SDL_image.h>
namespace Engine {
	class Entity {
	public:
		virtual ~Entity() {};
		virtual void Update() { collider->UpdateBorders(destRect); }
		void Render() { Engine::TextureManager::Draw(texture, sourceRect, destRect); }
	protected:
		float posX;
		float posY;
		Engine::Collider* collider;
		SDL_Rect sourceRect;
		SDL_Rect destRect;
		SDL_Texture* texture;
	};
}