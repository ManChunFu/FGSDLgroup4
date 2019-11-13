#include "Scene.h"
#include "CollisionManager.h"
#include "EntityManager.h"
#include "Text.h"
#include "UIManager.h"
namespace Engine {
	int Scene::idCtr = 0;
	Scene::Scene(Application* app, InputManager* input)
	{
		colManager = new Engine::CollisionManager();
		entityManager = new Engine::EntityManager();
		inputManager = input;
		application = app;
		idCtr++;
	}
	void Scene::Shutdown()
	{
		if (entityManager) 
		{
			entityManager->Shutdown();
			delete entityManager;
		}
		entityManager = nullptr;
		if (colManager)
		{
			colManager->Shutdown();
			delete colManager;
		}
		colManager = nullptr;
	}
	void Scene::Update()
	{
		entityManager->Update();
	}
	void Scene::HandleEvents()
	{
		colManager->Update();
	}
	void Scene::Render()
	{
		entityManager->Render();
	}
}
