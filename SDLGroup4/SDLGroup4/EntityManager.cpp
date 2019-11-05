#include "EntityManager.h"
#include "Entity.h"
namespace Engine {
	std::vector<Entity*> EntityManager::entities;
	void EntityManager::Update()
	{
		for (auto item : entities)
		{ item->Update(); }
	}
	void EntityManager::Render()
	{
		for (auto item : entities)
		{ item->Render(); }
	}
	void EntityManager::AddEntity(Entity* add)
	{ entities.push_back(add); }
	void EntityManager::Shutdown()
	{
		for (auto item : entities)
		{
			delete item;
		}
		entities.clear();
	}
}