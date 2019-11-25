#pragma once
#include "Collider.h"
#include "CircleCollider.h"

	class BoxCollider : public Engine::Collider
	{
		// Inherited via Collider
	public:
		BoxCollider(SDL_Rect destRect, float rotation, std::string colliderTag, Engine::Entity* entity) : Collider(colliderTag, entity)
		{
			UpdateCollider(destRect, rotation);
			parentCollider = new CircleCollider(destRect, colliderTag, entity);
			parentCollider->ThisBoxCollider = this;
			parentCollider->UpdateCollider(destRect, 0);
		};
		virtual void UpdateCollider(SDL_Rect destrect, float rotation) override;
		virtual bool TestCollision(Collider* other) override;
		bool BoxToBoxCollision(BoxCollider* other);
		float radius;
		virtual void Shutdown() override { Engine::Collider::Shutdown(); parentCollider = nullptr; }
		Engine::Vector2D middlePoint;
		std::vector<Collider*> collisions;
		Engine::Vector2D points[4];
		float Width() { return points[3].X - points[0].X; }
	private:
		CircleCollider* parentCollider;
	};
