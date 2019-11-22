#pragma once
#include "Collider.h"
class BoxCollider;
	class CircleCollider : public Engine::Collider
	{
	public:
		virtual void Shutdown() override 
		{ 
			Engine::Collider::Shutdown(); 
			if(ThisBoxCollider) delete ThisBoxCollider; 
			ThisBoxCollider = nullptr; 
		};
		CircleCollider(SDL_Rect destRect, std::string colliderTag, Engine::Entity* entity) : Collider(colliderTag, entity)
		{
			
			Engine::Scene::ActiveScene->CollisionManager()->AddNewCollider(this);
			UpdateCollider(destRect, 0);
		};
		BoxCollider* ThisBoxCollider;
		// Inherited via Collider
		virtual void UpdateCollider(SDL_Rect destrect, float rotation) override;
		virtual bool TestCollision(Collider* other) override;
		
		
	private:
		bool BoxToCircleCollision(BoxCollider* box);
		bool CircleToCircleCollision(CircleCollider* circle);
	};

