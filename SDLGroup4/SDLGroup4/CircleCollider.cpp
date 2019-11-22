#include "CircleCollider.h"
#include "BoxCollider.h"
#include <iostream>



void CircleCollider::UpdateCollider(SDL_Rect destRect, float rotation)
{
	radius = ((destRect.x + destRect.w - destRect.x) + (destRect.y + destRect.h - destRect.y)) * 0.5f;
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
			return CircleToCircleCollision(circle);
		}
	}
	std::cout << "Not valid collider!" << std::endl;
	return false;
}

bool CircleCollider::BoxToCircleCollision(BoxCollider* box)
{
	float distance = (middlePoint - box->middlePoint).X + (middlePoint - box->middlePoint).Y;
	if (distance < radius + box->radius) return true;
	else return false;
}

bool CircleCollider::CircleToCircleCollision(CircleCollider* circle)
{
	float distance = abs((circle->middlePoint - middlePoint).X) + abs((circle->middlePoint - middlePoint).Y);
	if (distance < radius + circle->radius) return true;
	else return false;
}
