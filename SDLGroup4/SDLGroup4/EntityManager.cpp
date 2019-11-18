#include "EntityManager.h"
#include "Entity.h"
namespace Engine {
	void EntityManager::Update()
	{
		for (Entity* item : entities)
		{ item->Update(); }
	}
	void EntityManager::Render()
	{
		for (auto item : entities)
		{ item->Render(); }
	}
	void EntityManager::RemoveEntity(Entity* ent)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			if (entities[i] == ent) 
			{
				entities.erase(entities.begin() + i);
			}
		}
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