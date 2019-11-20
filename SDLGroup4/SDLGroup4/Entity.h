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
namespace Engine {
	class Entity {
	public:
		virtual ~Entity() {}
		Entity() { Engine::Scene::ActiveScene->AddEntity(this); };
		void AddCollider(std::string tag){ collider = new Engine::Collider(destRect, tag, this); }
		void AddSprite(std::string _name, float scaleX, float scaleY);
		void AddSprite(std::string _name);
		virtual void Update();
		void Render();
		Engine::Animator animator;
		Vector2D position;
		void UpdateCollisionBox();
		Engine::Collider* collider = nullptr;
		float ScaleX = 1, ScaleY = 1;
		int GetSpriteWidth() { return destRect.w; };
		int GetSpriteHeight() { return destRect.h; };
		bool PlayAnimation = false;
	protected:
		virtual void OnCollisionEnter(Engine::Collider* other) {}
		SDL_Rect destRect = {0,0,0,0};
	private:
		SDL_Rect sourceRect = { 0,0,0,0 };
		SDL_Texture* texture = nullptr;
	};

}