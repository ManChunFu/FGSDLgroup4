#include "CollisionManager.h"
#include "Collider.h"
#include<algorithm> 
#include <iostream>
namespace Engine {
	std::vector<Collider*> CollisionManager::colliders;
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
				if (colliders[i] != colliders[a] && colliders[i]->LeftBorder() < colliders[a]->RightBorder() && 
					colliders[i]->TopBorder() < colliders[a]->BottomBorder() && colliders[i]->RightBorder() > colliders[a]->LeftBorder() 
				    && colliders[i]->BottomBorder() > colliders[a]->TopBorder())
				{ 
					if (colliders[i]->HasSurface() && colliders[a]->HasSurface())
					{
						int startXI = std::max(colliders[a]->LeftBorder() - colliders[i]->LeftBorder(), 0);
						int startYI = std::max(colliders[a]->TopBorder() - colliders[i]->TopBorder(), 0);
						int width = std::min(colliders[i]->RightBorder() - colliders[a]->LeftBorder(), colliders[a]->RightBorder() - colliders[i]->LeftBorder());
						int height = std::min(colliders[i]->BottomBorder() - colliders[a]->TopBorder(), colliders[a]->BottomBorder() - colliders[i]->TopBorder());
						
						
						int startXA = std::max(colliders[i]->LeftBorder() - colliders[a]->LeftBorder(), 0);
						int startYA = std::max(colliders[i]->TopBorder() - colliders[a]->TopBorder(), 0);


						if (colliders[i]->CheckAreaForAlpha(startXI, startYI, width, height) && colliders[a]->CheckAreaForAlpha(startXA, startYA, width, height)) {

						}
					}
					else
					{
						colliders[a]->collisions.push_back(colliders[i]);
						colliders[i]->collisions.push_back(colliders[a]);
					}
				
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
