#include "Scene.h"
#include "CollisionManager.h"
#include "EntityManager.h"
#include "Text.h"
#include "UIManager.h"
#include "Entity.h"
namespace Engine {
	int Scene::idCtr = 0;
	Scene* Scene::ActiveScene = nullptr;
	Scene::Scene(Application* app, InputManager* input)
	{
		ActiveScene = this;
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
		for (Entity* i : destroyQueue)
		{
			if (i->collider) colManager->RemoveCollider(i->collider);
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

	void Scene::Start()
	{
		ActiveScene = this;
		colManager = new Engine::CollisionManager();
		entityManager = new Engine::EntityManager();
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
