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
#include "SceneManager.h"
namespace Engine {
	class Entity {
	public:
		virtual ~Entity() {}
		Entity() { Engine::AbstractionModule::ActiveScene->AddEntity(this); };
		void AddCollider(std::string tag){ collider = new Engine::Collider(destRect, tag, this); }
		void AddSprite(std::string _name, int scaleX, int scaleY);
		void AddSprite(std::string _name);
		virtual void Update();
		void Render();
		Engine::Animator animator;
		Vector2D position;

	protected:
		virtual void OnCollisionEnter(Engine::Collider* other) {}
		Engine::Collider* collider = nullptr;
		SDL_Rect destRect;
	private:
		SDL_Rect sourceRect;
		SDL_Texture* texture = nullptr;
	};

}