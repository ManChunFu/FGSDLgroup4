#pragma once
#include <Vector2D.h>
#include <vector>
class Node
{
public:
	Node(Engine::Vector2D position, float hCost, Node* parent); 
		
	std::vector<Node*>Parent;
	Engine::Vector2D Position;
	float GCost;
	float HCost;
	float FCost = (GCost + HCost);
	bool IsStartPoint;
	bool NodeCompleted;
};
	
	
