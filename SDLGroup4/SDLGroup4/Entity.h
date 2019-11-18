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
		void AddCollider(std::string tag){ collider = new Engine::Collider(destRect, tag, this); }
		void AddSprite(std::string _path, int scaleX, int scaleY);
		void AddSprite(std::string _path);
		virtual void Update();
		void Render();
		Engine::Animator animator;
		Vector2D* position = nullptr;

	protected:
		virtual void OnCollisionEnter(Engine::Collider* other) {}
		Engine::Collider* collider = nullptr;
		SDL_Rect destRect;
	private:
		SDL_Rect sourceRect;
		SDL_Texture* texture = nullptr;
		Scene* scene = nullptr;
	};

}