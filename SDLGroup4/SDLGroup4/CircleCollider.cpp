#include "CircleCollider.h"
#include "BoxCollider.h"

void CircleCollider::UpdateCollider(SDL_Rect destRect, float rotation)
{
	if(destRect.w > destRect.h) radius = destRect.w * 0.5f;
	else radius = destRect.h * 0.5f;
	
	middlePoint.X = destRect.x + destRect.w - radius;
	middlePoint.Y = destRect.y + destRect.h - radius;
}

bool CircleCollider::TestCollision(Collider* other)
{
	CircleCollider* circle = dynamic_cast<CircleCollider*>(other);
	if (circle)
	{
		if (circle->ThisBoxCollider) 
		{
			if (CircleToCircleCollision(circle)) 
			{
				if (ThisBoxCollider) return ThisBoxCollider->BoxToBoxCollision(circle->ThisBoxCollider);
				else return BoxToCircleCollision(circle->ThisBoxCollider);
			}
			return false;
		}
		else 
		{
			if (ThisBoxCollider && CircleToCircleCollision(circle)) return BoxToCircleCollision(ThisBoxCollider, circle);
			return CircleToCircleCollision(circle);
		}
	}
	return false;
}

void CircleCollider::AddCollision(Collider* other)
{
	if (ThisBoxCollider) 
	{
		for (auto i : ThisBoxCollider->collisions)
		{ if (i == other) return; }
	}
	else
	{
		for (auto i : collisions)
		{  if (i == other) return; }
	}

	if (ThisBoxCollider) ThisBoxCollider->collisions.push_back(other);
	else collisions.push_back(other);
}

void CircleCollider::ClearCollision()
{
	if (ThisBoxCollider)
	{
		ThisBoxCollider->collisionExit.clear();
	}

	else collisionExit.clear();
}

void CircleCollider::RemoveCollision(Collider* other)
{
	int length = collisions.size();
	if (ThisBoxCollider) length = ThisBoxCollider->collisions.size();
	if (length > 0)
	{
		for (int i = 0; i < length; i++)
		{
			if (ThisBoxCollider)
			{
				if (ThisBoxCollider->collisions[i] == other)
				{
					ThisBoxCollider->collisions.erase(ThisBoxCollider->collisions.begin() + i);
					ThisBoxCollider->collisionExit.push_back(other);
					return;
				}
			}
			else
			{
				if (collisions[i] == other)
				{
					collisions.erase(collisions.begin() + i);
					collisionExit.push_back(other);
					return;
				}
			}
		}
	}
}

bool CircleCollider::BoxToCircleCollision(BoxCollider* box)
{
	float distance = sqrt(pow((middlePoint - box->middlePoint).X ,2) + pow((middlePoint - box->middlePoint).Y, 2));
	if (distance < radius + box->radius) 
		return true;
	else return false;
}

bool CircleCollider::BoxToCircleCollision(BoxCollider* box, CircleCollider* circle)
{
	float distance = sqrt(pow((circle->middlePoint - box->middlePoint).X, 2) + pow((circle->middlePoint - box->middlePoint).Y, 2));
	if (distance < circle->radius + (box->Width() * 0.5f)) return true;
	else return false;
}

bool CircleCollider::CircleToCircleCollision(CircleCollider* circle)
{
	float distance = sqrt(pow((circle->middlePoint - middlePoint).X, 2) + pow((circle->middlePoint - middlePoint).Y, 2));
	if (distance < radius + circle->radius) return true;
	else return false;
}
