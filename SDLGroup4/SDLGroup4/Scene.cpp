#include "Scene.h"
#include "CollisionManager.h"
#include "EntityManager.h"
#include "Text.h"
#include "UIManager.h"
#include "SceneManager.h"
namespace Engine {
	int Scene::idCtr = 0;
	Scene::Scene(Application* app, InputManager* input)
	{
		AbstractionModule::ActiveScene = this;
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
		for (auto i : destroyQueue)
		{
			entityManager->RemoveEntity(i);
			delete i;
		}
		destroyQueue.clear();
		for (Entity* add : addQueue)
		{ entityManager->AddEntity(add); }
		addQueue.clear();
	}
	void Scene::HandleEvents()
	{
		colManager->Update();
	}
	void Scene::Render()
	{
		entityManager->Render();
	}

	void Scene::AddEntity(Entity* ent)
	{
		addQueue.push_back(ent);
	}

	void Scene::Destroy(Entity* target)
	{
		destroyQueue.push_back(target);
	}

}
