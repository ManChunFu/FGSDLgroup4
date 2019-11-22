#pragma once
#include <SDL_rect.h>
#include <SDL_Image.h>
#include <string>
#include <vector>
#include "CollisionManager.h"
#include "Scene.h"
namespace Engine {
	class Entity;
	class Collider {
	public:
		
		~Collider()
		{
		}
		virtual void Shutdown(){
			GameObject = nullptr;
			collisions.clear();
		}
		virtual void UpdateCollider(SDL_Rect destrect, float rotation) {};
		bool solid = false;
		Entity* GameObject;
		std::vector<Collider*> collisions;
		std::string tag = "";
		virtual bool TestCollision(Collider* other) = 0;
		float radius;
		bool movable = true;
		Engine::Vector2D middlePoint;
	protected:
		Collider(std::string colliderTag, Entity* entity)
		{
			GameObject = entity;
			tag = colliderTag;
		};
	private:
		float scale = 0;

	};
}