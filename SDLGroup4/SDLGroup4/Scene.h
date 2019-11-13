#pragma once
#include "UIManager.h"
#include "Text.h"
#include "Button.h"
namespace Engine 
{
	class EntityManager;
	class CollisionManager;
	class Scene
	{
	public:
		Scene();
		virtual ~Scene(){}
		void Shutdown();
		void Update();
		void HandleEvents();
		void Render();
		const int id = idCtr;
		CollisionManager* CollisionManager() { return colManager; };
		EntityManager* EntityManager() { return entityManager; };
		virtual void SetUpUI() = 0;
	private:
		static int idCtr;
		Engine::CollisionManager* colManager;
		Engine::EntityManager* entityManager;
	};
}

