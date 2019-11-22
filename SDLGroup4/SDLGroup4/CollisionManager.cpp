#include "CollisionManager.h"
#include "Collider.h"
#include<algorithm> 
#include <iostream>
#include "Entity.h"
namespace Engine {
	void CollisionManager::AddNewCollider(Engine::Collider* col)
	{ colliders.push_back(col); }
	void CollisionManager::Update()
	{
		for (int i = 0; i < colliders.size(); i++)
		{ colliders[i]->collisions.clear(); }
		for (int i = 0; i < colliders.size(); i++)
		{
			for (int a = i + 1; a < colliders.size(); a++)
			{
				if (colliders[i]->TestCollision(colliders[a])) 
				{
					colliders[i]->collisions.push_back(colliders[a]);
					colliders[a]->collisions.push_back(colliders[i]);
				}
			}
		}
	}
	void CollisionManager::Shutdown()
	{
		for (auto col : colliders)
		{
			col->Shutdown();
			delete col; 
		}
		colliders.clear();
	}
	void CollisionManager::RemoveCollider(Engine::Collider* col)
	{
		for (int i = 0; i < colliders.size(); i++)
		{
			if (colliders[i] == col) 
			{
				colliders[i]->Shutdown();
				delete colliders[i];
				colliders.erase(colliders.begin() + i);
				return;
			}
		}
	}
}
