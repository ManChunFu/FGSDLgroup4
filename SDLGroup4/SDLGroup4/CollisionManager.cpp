#include "CollisionManager.h"
#include "Collider.h"
namespace Engine {
	void CollisionManager::AddNewCollider(Engine::Collider* col)
	{ colliders.push_back(col); }
	void CollisionManager::Update()
	{
		for (int i = 0; i < colliders.size(); i++)
		{
			for (int a = 0; a < colliders.size(); a++)
			{
				if (colliders[i] != colliders[a] && (colliders[i]->LeftBorder < colliders[a]->RightBorder && colliders[i]->TopBorder < colliders[a]->BottomBorder) &&
					(colliders[i]->RightBorder > colliders[a]->LeftBorder && colliders[i]->BottomBorder > colliders[a]->TopBorder))
				{
					colliders[i]->collisionTarget = colliders[a];
				}
			}
		}
	}
	void CollisionManager::Shutdown()
	{
		for (auto col : colliders)
		{ delete col; }
		colliders.clear();
	}
}
