#include "Node.h"

Node::Node(Engine::Vector2D position, int hCost, Node* parent) : Position(position), HCost(hCost)
{
	if (parent != nullptr)
	{
		Parent.push_back(parent);
		
		Engine::Vector2D difference = parent->Position - position;
		GCost = parent->GCost + 1; // (fabsf(difference.X) == 1 && fabsf(difference.Y) == 1 ? 14 : 10);
	}
	else
	{
		IsStartPoint = true;
		GCost = 0;
	}
	FCost = GCost + HCost;
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



