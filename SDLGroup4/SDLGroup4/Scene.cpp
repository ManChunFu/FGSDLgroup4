#include "Scene.h"
#include "CollisionManager.h"
#include "EntityManager.h"
namespace Engine {
	int Scene::idCtr = 0;
	Scene::Scene()
	{
		colManager = new Engine::CollisionManager();
		entityManager = new Engine::EntityManager();
		SetUpUI();
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
