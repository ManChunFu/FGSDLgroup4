#pragma once
#include <Vector2D.h>
#include <vector>
class Node
{
public:
	Node(Engine::Vector2D position, float hCost, Node* parent); 
	~Node();
		
	std::vector<Node*>Parent;
	Engine::Vector2D Position;
	float GCost;
	float HCost;
	float FCost = (GCost + HCost);
	bool IsStartPoint;
	bool NodeCompleted;

	float GetHCost(Engine::Vector2D targetPos, Engine::Vector2D newNodePos);

};
	
	
