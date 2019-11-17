#include "Node.h"

Node::Node(Engine::Vector2D position, float hCost, Node* parent) : Position(position), HCost(hCost)
{
	if (parent != nullptr)
	{
		/*float x = parent->Position->X - position->X;
		float y = parent->Position->Y - position->Y;
		*/
		Parent.push_back(parent);
		/*Engine::Vector2D difference;
		difference.X = x;
		difference.Y = y;*/
		Engine::Vector2D difference = parent->Position - position;
		GCost = parent->GCost * (fabsf(difference.X) == 1 && fabsf(difference.Y) == 1 ? 14.f : 10.f);
	}
	else
	{
		IsStartPoint = true;
		GCost = 0;
	}
}

bool Node::HasThisParent(Node* node)
{
	for (auto parent : Parent)
	{
		if (parent == node)
			return true;
	}
	return false;
}



