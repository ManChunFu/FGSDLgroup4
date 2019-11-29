#include "CollisionManager.h"
#include "Collider.h"
#include<algorithm> 
#include "Entity.h"
namespace Engine {
	void CollisionManager::AddNewCollider(Engine::Collider* col)
	{ colliders.push_back(col); }
	void CollisionManager::Update()
	{
		for (int i = 0; i < colliders.size(); i++)
		{ colliders[i]->ClearCollision(); }
		for (int i = 0; i < colliders.size(); i++)
		{
			for (int a = i + 1; a < colliders.size(); a++)
			{
				if (colliders[i]->tag != colliders[a]->tag && colliders[i]->TestCollision(colliders[a])) 
				{
					colliders[i]->AddCollision(colliders[a]);
					colliders[a]->AddCollision(colliders[i]);
				}
				else
				{
					colliders[i]->RemoveCollision(colliders[a]);
					colliders[a]->RemoveCollision(colliders[i]);
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
		
		BoxCollider* box = dynamic_cast<BoxCollider*>(col);
		if (box) col = box->ParentCollider();
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
