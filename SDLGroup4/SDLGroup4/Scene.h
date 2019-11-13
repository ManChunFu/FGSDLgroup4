#pragma once
#include "UIManager.h"
#include "Text.h"
#include "Button.h"
namespace Engine 
{
	class Application;
	class EntityManager;
	class CollisionManager;
	class InputManager;
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
		EntityManager* EntityManager() { return entityManager; };
		virtual void SetUpUI() = 0;
		Engine::Application* application;
	protected:
		Engine::InputManager* inputManager;
	private:
		static int idCtr;
		Engine::CollisionManager* colManager;
		Engine::EntityManager* entityManager;
	};
}
