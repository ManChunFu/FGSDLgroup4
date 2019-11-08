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
			for (int a = 0; a < colliders.size(); a++)
			{
				if (colliders[i] != colliders[a] && colliders[i]->LeftBorder() < colliders[a]->RightBorder() && 
					colliders[i]->TopBorder() < colliders[a]->BottomBorder() && colliders[i]->RightBorder() > colliders[a]->LeftBorder() 
				    && colliders[i]->BottomBorder() > colliders[a]->TopBorder())
				{ 
					if (colliders[i]->HasSurface() && colliders[a]->HasSurface())
					{
						int checkAreaWidth = (colliders[a]->RightBorder() - colliders[i]->LeftBorder());
						if (checkAreaWidth < colliders[i]->Width()) checkAreaWidth = colliders[i]->Width() - (colliders[i]->RightBorder() - colliders[a]->LeftBorder());
						
						int checkAreaHeight = (colliders[a]->BottomBorder() - colliders[i]->TopBorder());
						if (checkAreaHeight > colliders[i]->Height()) checkAreaHeight = colliders[i]->Height() - (colliders[i]->BottomBorder() - colliders[a]->TopBorder());

						int colliderIStartX = std::max(colliders[a]->LeftBorder() - colliders[i]->LeftBorder(), 0);
						int colliderIStartY = std::max(colliders[a]->TopBorder() - colliders[i]->TopBorder(), 0);
						int colliderAStartX = std::max(colliders[a]->RightBorder() - colliders[i]->RightBorder(), 0);
						int colliderAStartY = std::max(colliders[a]->BottomBorder() - colliders[i]->BottomBorder(), 0);
						if(colliders[i]->CheckAreaForAlpha(colliderIStartX, colliderIStartY, checkAreaWidth, checkAreaHeight) && 
							colliders[a]->CheckAreaForAlpha(colliderAStartX, colliderAStartY, checkAreaWidth, checkAreaHeight))
						{
							std::cout << colliders[i]->tag;
						}
					}
					else colliders[i]->collisions.push_back(colliders[a]);
				
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
