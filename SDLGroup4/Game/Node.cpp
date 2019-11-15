#include "Node.h"

Node::Node(Engine::Vector2D position, float hCost, Node* parent) : Position(position), HCost(hCost)
{
	if (parent != nullptr)
	{
		Parent.push_back(parent);
		Engine::Vector2D difference = (parent->Position - position);
		GCost = parent->GCost * (fabsf(difference.X) == 1 && fabsf(difference.Y) == 1 ? 14.f : 10.f);
	}
	else
	{
		IsStartPoint = true;
		GCost = 0;
	}
}

Node::~Node()
{
}

void Node::GetHCost(Engine::Vector2D newNodePos)
{
}
