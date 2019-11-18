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
				if (colliders[i] != colliders[a] && colliders[i]->LeftBorder() < colliders[a]->RightBorder() && 
					colliders[i]->TopBorder() < colliders[a]->BottomBorder() && colliders[i]->RightBorder() > colliders[a]->LeftBorder() 
				    && colliders[i]->BottomBorder() > colliders[a]->TopBorder())
				{ 
					colliders[a]->collisions.push_back(colliders[i]);
					colliders[i]->collisions.push_back(colliders[a]);
					if (colliders[i]->solid && colliders[a]->solid) 
					{
						int directionX = 0;
						int directionY = 0;
						int offset = 1;
						if (colliders[i]->TopBorder() < colliders[a]->BottomBorder() && colliders[a]->TopBorder() < colliders[i]->TopBorder()) directionY = -(colliders[i]->TopBorder() - colliders[a]->BottomBorder());
						if (colliders[a]->TopBorder() < colliders[i]->BottomBorder() && colliders[a]->TopBorder() > colliders[i]->TopBorder()) directionY = (colliders[a]->TopBorder() - colliders[i]->BottomBorder());
						if (colliders[i]->LeftBorder() < colliders[a]->RightBorder() && colliders[a]->LeftBorder() < colliders[i]->LeftBorder()) directionX = -(colliders[i]->LeftBorder() - colliders[a]->RightBorder());
						if (colliders[a]->LeftBorder() < colliders[i]->RightBorder() && colliders[a]->LeftBorder() > colliders[i]->LeftBorder()) directionX = (colliders[a]->LeftBorder() - colliders[i]->RightBorder());
						if (abs(directionX) > abs(directionY)) directionX = 0; 
						else directionY = 0;
						if(directionX > 0) colliders[i]->GameObject->position.X = colliders[a]->RightBorder() - offset;
						if (directionX < 0) colliders[i]->GameObject->position.X = colliders[a]->LeftBorder() + offset - (colliders[i]->RightBorder() - colliders[i]->LeftBorder());
						if (directionY > 0) colliders[i]->GameObject->position.Y = colliders[a]->BottomBorder() - offset;
						if (directionY < 0) colliders[i]->GameObject->position.Y = colliders[a]->TopBorder() + offset - (colliders[i]->BottomBorder() - colliders[i]->TopBorder());
						colliders[i]->GameObject->UpdateCollisionBox();
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
