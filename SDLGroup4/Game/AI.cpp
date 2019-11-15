#include "AI.h"
#include <math.h>

bool AI::EnterDangerZone(float radiusLimit, Engine::Vector2D position, Engine::Vector2D targetPosition)
{
	return (hypotf(fabsf(targetPosition.X - position.X), fabsf(targetPosition.Y - position.Y)) <= radiusLimit);
}

std::vector<Engine::Vector2D> AI::pathFinding(Engine::Vector2D targetPosition, Engine::Vector2D startPosition)
{
	std::vector<Node*> examinatedNodArea;
	examinatedNodArea.push_back(new Node(startPosition, GetHCost(targetPosition, startPosition), nullptr));
	
	std::vector<Node*> workingNodes;
	bool reachTarget = false;

	float currentSmallestFCost = 1000;
	do
	{
		//int miniFCost = (int)

	} while (!reachTarget && !NodeCompleted(examinatedNodArea));

	return std::vector<Engine::Vector2D>();
}

bool AI::NodeCompleted(std::vector<Node*> nodeList)
{
	for (auto node : nodeList)
	{
		if (!node->NodeCompleted)
			return false;
	}
	return true;
}




