#include "CircleCollider.h"
#include "BoxCollider.h"
#include <iostream>



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
	std::cout << "Not valid collider!" << std::endl;
	return false;
}

void CircleCollider::AddCollision(Collider* other)
{
	if (ThisBoxCollider) ThisBoxCollider->collisions.push_back(other);
	else collisions.push_back(other);
}

void CircleCollider::ClearCollision()
{
	if (ThisBoxCollider) ThisBoxCollider->collisions.clear();
	else collisions.clear();
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
