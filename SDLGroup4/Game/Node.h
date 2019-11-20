#pragma once
#include <Vector2D.h>
#include <vector>
class Node
{
public:
	Node(Engine::Vector2D position, int hCost, Node* parent); 
	bool HasThisParent(Node* node);
		
	std::vector<Node*>Parent;
	Engine::Vector2D Position;
	int GCost;
	int HCost;
	int FCost; 
	bool IsStartPoint;
	bool NodeCompleted;

};