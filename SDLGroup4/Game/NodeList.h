#pragma once
#include "Node.h"

class NodeList
{
public:
	std::vector<Node*> examinatedNodeArea;
	std::vector<Node*> workingNodes;

	void ClearNodeList()
	{
		for (auto examinatedNode : examinatedNodeArea)
			delete examinatedNode;

		examinatedNodeArea.clear();
	}

	int miniFCost = 0;
	int miniHCostOfAllMiniFCosts = 0;
	int currentSmallestFCost = 0;
};
