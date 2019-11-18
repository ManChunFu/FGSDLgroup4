#pragma once
#include "UIManager.h"
#include "Text.h"
#include "Button.h"
#include <vector>
namespace Engine 
{
	class Application;
	class EntityManager;
	class CollisionManager;
	class InputManager;
	class Entity;
	class Scene
	{
	public:
		Scene(Application* app, InputManager* input);
		virtual ~Scene(){}
		virtual void Shutdown();
		virtual void Update();
		virtual void HandleEvents();
		virtual void Render();
		const int id = idCtr;
		CollisionManager* CollisionManager() { return colManager; };
		virtual void SetUpUI() = 0;
		void AddEntity(Entity* ent);
		void Destroy(Entity* target);
		Engine::Application* application;
	protected:
		Engine::InputManager* inputManager;
	private:
		std::vector<Entity*> addQueue;
		std::vector<Entity*> destroyQueue;
		Engine::EntityManager* entityManager;
		static int idCtr;
		Engine::CollisionManager* colManager;
	};
}
