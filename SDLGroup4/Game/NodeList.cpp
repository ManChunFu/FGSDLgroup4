#include "NodeList.h"
#include "Node.h"
#include "MainScene.h"


NodeList::NodeList(Engine::Vector2D targetPos, Engine::Vector2D startPos) ://, std::vector<Engine::Vector2D*> obstacleList) :
	targetPos(targetPos), startPos(startPos) {}//, obstacleList(obstacleList){}

NodeList::~NodeList()
{
	for (auto examinatedNode : examinatedNodeArea)
		delete examinatedNode;

	examinatedNodeArea.clear();
}

std::vector<Engine::Vector2D> NodeList::GetPath()
{
	examinatedNodeArea.push_back(new Node(startPos, GetHCost(startPos, targetPos), nullptr));

	bool reachTarget = false;
	currentSmallestFCost = 1000;
	
	do 
	{
		SetWorkingNodes();

		if (workingNodes.size() == 0)
			break;

		for (Node* current : workingNodes)
		{
			Engine::Vector2D closeEnough = targetPos - current->Position;
			float distance = fabsf(closeEnough.X) + fabsf(closeEnough.Y);
			
			if (distance < 4)
			{
				reachTarget = true;
				Node* nodesToTarget = current;
				Path.push_back(nodesToTarget->Position);

				while (nodesToTarget->Parent.size() > 0)
				{
					Node* closestParent = nodesToTarget->Parent[0];
					if (nodesToTarget->Parent.size() > 1)
						for (uint8_t index = 1; index < nodesToTarget->Parent.size(); index++)
						{
							if (nodesToTarget->Parent[index]->GCost < closestParent->GCost)
								closestParent = nodesToTarget->Parent[index];
						}
					Path.push_back(closestParent->Position);
					nodesToTarget = closestParent;
				}
			}

			for (auto move : moveByStraightLine)
			{
				Engine::Vector2D newMovePosStraight = current->Position + move;
				if ((newMovePosStraight.X >= sceneSizeMinX && newMovePosStraight.X <= sceneSizeMaxX) && 
					(newMovePosStraight.Y >= sceneSizeMinY && newMovePosStraight.Y <= sceneSizeMaxY))
				{
					if (!CheckObstacle(newMovePosStraight))
					{
						Node* existingNode = CheckExistingNode(newMovePosStraight);
						if (existingNode == nullptr)
							examinatedNodeArea.push_back(new Node(newMovePosStraight, GetHCost(newMovePosStraight, targetPos), current));
						else if (!current->HasThisParent(existingNode))
							current->Parent.push_back(existingNode);
					}
				}
			}

			for (auto move : moveByDiagnoalLine)
			{
				Engine::Vector2D newMovePosDiagnoal = current->Position + move;
				Engine::Vector2D diagnoalNeighborX= current->Position;
				diagnoalNeighborX.X += move.X;
				Engine::Vector2D diagnoalNeighborY = current->Position;
				diagnoalNeighborY.Y += move.Y;

				if ((newMovePosDiagnoal.X >= sceneSizeMinX && newMovePosDiagnoal.X <= sceneSizeMaxX) &&
					(newMovePosDiagnoal.Y >= sceneSizeMinY && newMovePosDiagnoal.Y <= sceneSizeMaxY))
				{
					if (!CheckObstacle(newMovePosDiagnoal))
					{
						if (!CheckObstacle(diagnoalNeighborX) && !CheckObstacle(diagnoalNeighborY))
						{
							Node* existingNode = CheckExistingNode(newMovePosDiagnoal);
							if (existingNode == nullptr)
								examinatedNodeArea.push_back(new Node(newMovePosDiagnoal, GetHCost(newMovePosDiagnoal, targetPos), current));
							else if (!current->HasThisParent(existingNode))
								current->Parent.push_back(existingNode);
						}
					}
				}
			}
			current->NodeCompleted = true;
		}
	} while (!reachTarget && !CheckAllNodesCompleted());

	return Path;
}


void NodeList::SetWorkingNodes()
{
	workingNodes.clear();

	int arrayCount = examinatedNodeArea.size();
	if (arrayCount < 1)
	{
		miniFCost = 0;
		return;
	}
/*Get miniFCost*/
	for (auto node : examinatedNodeArea)
	{
		if (!node->NodeCompleted)
		{
			if (miniFCost == 0 || node->FCost < miniFCost)
				miniFCost = node->FCost;
		}
	}	
/*Compare to the current smallestFCost*/
	if (miniFCost > currentSmallestFCost)
	{
		for (auto node : examinatedNodeArea)
		{
			if (node->FCost == miniFCost)
				workingNodes.push_back(node);
		}
	}	
	else
	{	
		currentSmallestFCost = miniFCost;

		for (auto node : examinatedNodeArea)
		{
			if (!node->NodeCompleted)
			{
				if (node->FCost == miniFCost)
					if (miniHCostOfAllMiniFCosts == 0 || node->HCost < miniHCostOfAllMiniFCosts)
						miniHCostOfAllMiniFCosts = node->HCost;
			}
		}

		for (auto node : examinatedNodeArea)
		{
			if (!node->NodeCompleted)
			{
				if (node->FCost == miniFCost && node->HCost == miniHCostOfAllMiniFCosts)
					workingNodes.push_back(node);
			}
		}
	}
}

bool NodeList::CheckObstacle(Engine::Vector2D newNodePos)
{
	for (auto obstacle : MainScene::obstacle)
	{
		Engine::Vector2D middlePoint = obstacle->position;
		middlePoint.X += 32;
		middlePoint.Y += 32;
		if (GetDistance(middlePoint, newNodePos) < 33)
		return true;
	}
	return false;
}

float NodeList::GetDistance(Engine::Vector2D position, Engine::Vector2D targetPosition)
{
	float distance = _hypotf(fabsf(targetPosition.X - position.X), fabsf(targetPosition.Y - position.Y));
	return distance;
}

Node* NodeList::CheckExistingNode(Engine::Vector2D newNodePos)
{
	for (auto node : examinatedNodeArea)
	{
		if (node->Position == newNodePos)
			return node;
	}
	return nullptr;
}

bool NodeList::CheckAllNodesCompleted()
{
	for (auto node : examinatedNodeArea)
	{
		if (!node->NodeCompleted)
			return false;
	}
	return true;
}


int NodeList::GetHCost(Engine::Vector2D newNodePos, Engine::Vector2D targetPos)
{
	int x = fabsf(targetPos.X - newNodePos.X);
	int y = fabsf(targetPos.Y - newNodePos.Y);
	
	if (x < y)
		return (y - x) + (hypotf(x, x));
	else
		return (x - y) + (hypotf(y, y));
}
