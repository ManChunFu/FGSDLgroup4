#include "BoxCollider.h"
#include <iostream>
#include "Window.h"
#include "Entity.h"
#include <SDL_render.h>
void BoxCollider::UpdateCollider(SDL_Rect destRect, float rotation)
{
	points[0].X = destRect.x;
	points[0].Y = destRect.y;
	points[1].Y = destRect.y;
	points[1].X = destRect.x + destRect.w;
	points[2].Y = destRect.y + destRect.h;
	points[2].X = destRect.x;
	points[3].X = destRect.x + destRect.w;
	points[3].Y = destRect.y + destRect.h;
	if(destRect.w > destRect.h) radius = destRect.w * 0.5f;
	else radius = destRect.h * 0.5f;
	middlePoint.X = ((points[3].X - points[0].X) * 0.5f) + points[0].X;
	middlePoint.Y = ((points[3].Y - points[0].Y) * 0.5f) + points[0].Y;
	if (parentCollider) parentCollider->UpdateCollider(destRect, 0);
	float lowestY = 2000;
	float lowestX = 2000;
	float highestX = 0;
	float highestY = 0;
	for (auto i : points)
	{
		if (i.Y < lowestY) lowestY = i.Y;
		if (i.Y > highestY) highestY = i.Y;
		if (i.X < lowestX) lowestX = i.X;
		if (i.X > highestX) highestX = i.X;
	}
}

bool BoxCollider::TestCollision(Collider* other)
{ return false; }

bool BoxCollider::BoxToBoxCollision(BoxCollider* other)
{
	float otherLowestY = 2000;
	float otherLowestX = 2000;
	float otherHighestX = 0;
	float otherHighestY = 0;
	for (auto i : other->points)
	{
		if (i.Y < otherLowestY) otherLowestY = i.Y;
		if (i.Y > otherHighestY) otherHighestY = i.Y;
		if (i.X < otherLowestX) otherLowestX = i.X;
		if (i.X > otherHighestX) otherHighestX = i.X;
	}
	float lowestY = 2000;
	float lowestX = 2000;
	float highestX = 0;
	float highestY = 0;
	for (auto i : points)
	{
		if (i.Y < lowestY) lowestY = i.Y;
		if (i.Y > highestY)highestY = i.Y;
		if (i.X < lowestX) lowestX = i.X;
		if (i.X > highestX) highestX = i.X;
	}
	for (auto i : points)
	{
		if (lowestX < otherHighestX && highestX > otherLowestX && lowestY < otherHighestY && highestY > otherLowestY) 
		{
			if (solid && other->solid)
			{
				int directionX = 0;
				int directionY = 0;
				int offset = 1;
				if (otherHighestX - i.X < i.X - otherLowestX && otherLowestX < lowestX) directionX = (otherHighestX - i.X);
				else directionX = (i.X - otherLowestX);
				if (otherHighestY - i.Y < i.Y - otherLowestY && otherLowestY < lowestY) directionY = (otherHighestY - i.Y);
				else directionY = (i.Y - otherLowestY);
				if(directionX != 0 && directionY != 0) 
				{
					if (directionY == (i.Y - otherLowestY) && directionX == (i.X - otherLowestX))
					{
						 if (abs(directionX) < abs(directionY)) directionX = 0;
						 else directionY = 0;
					}
					else if (directionY == (otherHighestY - i.Y) && directionX == (otherHighestX - i.X)) directionY = 0;
					else if (directionY == (otherHighestY - i.Y) && directionX == (i.X - otherLowestX)) 
					{
						directionX = 0;
					}
					else if (directionY == (i.Y - otherLowestY) && directionX == (otherHighestX - i.X)) directionY = 0;
					
				}

				if (directionX > 0)
				{
					if(movable)GameObject->position.X = otherHighestX;
					if(other->movable)other->GameObject->position.X = lowestX - other->GameObject->GetSpriteWidth() - offset;
				}
				if (directionX < 0)
				{
					if (movable)GameObject->position.X = otherLowestX - GameObject->GetSpriteWidth() ;
					if (other->movable)other->GameObject->position.X = highestX  + offset;
				}
				if (directionY > 0)
				{
					if (movable)GameObject->position.Y = otherHighestY;
					if (other->movable)other->GameObject->position.Y = lowestY - other->GameObject->GetSpriteHeight() - offset;
				}
				if (directionY < 0)
				{
					if (movable)GameObject->position.Y = otherLowestY - GameObject->GetSpriteHeight();
					if (other->movable) other->GameObject->position.Y = highestY + offset;
				}
				if(movable)GameObject->UpdateCollisionBox();
				if(other->GameObject && other->movable) other->GameObject->UpdateCollisionBox();
			}
			return true;
		}
	}
	return false;
}
