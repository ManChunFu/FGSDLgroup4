#include "BoxCollider.h"
#include <iostream>
#include "Window.h"

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
	radius = destRect.w * 0.5f;
	middlePoint.X = points[3].X - radius;
	middlePoint.Y = points[3].Y - radius;
	for (auto i : points)
	{
		i.X = ((i.X - middlePoint.X) * cos(rotation) - (middlePoint.Y - i.Y) * sin(rotation)) + middlePoint.X;
		i.Y = ((middlePoint.X - i.Y) * cos(rotation) - (i.X - middlePoint.X) * sin(rotation)) + middlePoint.Y;
		/*i.X -= middlePoint.X;
		i.Y -= middlePoint.Y;
		i.X = (i.X * cos(rotation)) - (i.Y * sin(rotation));
		i.Y = (i.X * sin(rotation)) - (i.Y * cos(rotation));
		i.X += middlePoint.X;
		i.Y += middlePoint.Y;*/
	}
	if (parentCollider) parentCollider->UpdateCollider(destRect, 0);
	SDL_Rect rect = { points[0].X, points[0].Y, points[1].X - points[0].X, points[2].Y - points[0].Y };
	SDL_RenderDrawRect(Engine::Window::Renderer, &rect);
}

bool BoxCollider::TestCollision(Collider* other)
{
	return false;
}

bool BoxCollider::BoxToBoxCollision(BoxCollider* other)
{
	float lowestY = 2000;
	float lowestX = 2000;
	float highestX = 0;
	float highestY = 0;
	for (auto i : other->points)
	{
		if (i.Y < lowestY) lowestY = i.Y;
		if (i.Y > highestY) highestY = i.Y;
		if (i.X < lowestX) lowestX = i.X;
		if (i.X > highestX) highestX = i.X;
	}
	for (auto i : points)
	{
		if (i.X < highestX && i.X > lowestX && i.Y < highestY && i.Y > lowestY)
			return true;
	}
	return false;
}
