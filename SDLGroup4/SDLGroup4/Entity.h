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
#include "BoxCollider.h"
#include "CircleCollider.h"
namespace Engine {
	class Entity {
	public:
		 ~Entity() { OnDestroy(); }
		Entity() { Engine::Scene::ActiveScene->AddEntity(this); };
		void AddCollider(std::string tag, bool boxCollider);
		void AddSprite(std::string _name, float scaleX, float scaleY);
		void AddSprite(std::string _name);
		virtual void Update();
		virtual void Render();
		Engine::Animator animator;
		Vector2D position;
		Vector2D lastPosition;
		void UpdateCollisionBox();
		Collider* collider;
		float ScaleX = 1, ScaleY = 1;
		int GetSpriteWidth() { return destRect.w; };
		int GetSpriteHeight() { return destRect.h; };
		bool PlayAnimation = false;
		float rotation = 0;
		SDL_Rect destRect = {0,0,0,0};
	protected:
		virtual void OnCollisionEnter(Engine::Collider* other) {}
		virtual void OnCollisionExit(Engine::Collider* other) {}
		virtual void OnDestroy() {};
		SDL_Rect sourceRect = { 0,0,0,0 };
		SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
	private:
		SDL_Texture* texture = nullptr;
	};

}