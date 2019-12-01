#include "Pathfinding.h"
#include "Node.h"
#include "MainScene.h"


Pathfinding::Pathfinding(Engine::Vector2D targetPos, Engine::Vector2D startPos) :
	targetPos(targetPos), startPos(startPos) {}

Pathfinding::~Pathfinding()
{
	Path.clear();

	nodeList.ClearNodeList();
}

std::vector<Engine::Vector2D> Pathfinding::GetPath()
{
	nodeList.examinatedNodeArea.push_back(new Node(startPos, GetHCost(startPos, targetPos), nullptr));

	bool reachTarget = false;
	nodeList.currentSmallestFCost = 1000;
	
	do 
	{
		SetWorkingNodes();

		if (nodeList.workingNodes.size() == 0)
			break;

		for (Node* current : nodeList.workingNodes)
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
							nodeList.examinatedNodeArea.push_back(new Node(newMovePosStraight, GetHCost(newMovePosStraight, targetPos), current));
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
								nodeList.examinatedNodeArea.push_back(new Node(newMovePosDiagnoal, GetHCost(newMovePosDiagnoal, targetPos), current));
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


void Pathfinding::SetWorkingNodes()
{
	nodeList.workingNodes.clear();

	int arrayCount = nodeList.examinatedNodeArea.size();
	if (arrayCount < 1)
	{
		nodeList.miniFCost = 0;
		return;
	}
/*Get miniFCost*/
	for (auto node : nodeList.examinatedNodeArea)
	{
		if (!node->NodeCompleted)
		{
			if (nodeList.miniFCost == 0 || node->FCost < nodeList.miniFCost)
				nodeList.miniFCost = node->FCost;
		}
	}	
/*Compare to the current smallestFCost*/
	if (nodeList.miniFCost > nodeList.currentSmallestFCost)
	{
		for (auto node : nodeList.examinatedNodeArea)
		{
			if (node->FCost == nodeList.miniFCost)
				nodeList.workingNodes.push_back(node);
		}
	}	
	else
	{	
		nodeList.currentSmallestFCost = nodeList.miniFCost;

		for (auto node : nodeList.examinatedNodeArea)
		{
			if (!node->NodeCompleted)
			{
				if (node->FCost == nodeList.miniFCost)
					if (nodeList.miniHCostOfAllMiniFCosts == 0 || node->HCost < nodeList.miniHCostOfAllMiniFCosts)
						nodeList.miniHCostOfAllMiniFCosts = node->HCost;
			}
		}

		for (auto node : nodeList.examinatedNodeArea)
		{
			if (!node->NodeCompleted)
			{
				if (node->FCost == nodeList.miniFCost && node->HCost == nodeList.miniHCostOfAllMiniFCosts)
					nodeList.workingNodes.push_back(node);
			}
		}
	}
}

bool Pathfinding::CheckObstacle(Engine::Vector2D newNodePos)
{
	for (auto obstacle : MainScene::obstacle)
	{
		if (obstacle->position.X + obstacle->destRect.w >= newNodePos.X &&
			newNodePos.X + 3 >= obstacle->position.X &&
			obstacle->position.Y + obstacle->destRect.h >= newNodePos.Y &&
			newNodePos.Y + 3 >= obstacle->position.Y)
			return true;
	}
	return false;
}

Node* Pathfinding::CheckExistingNode(Engine::Vector2D newNodePos)
{
	for (auto node : nodeList.examinatedNodeArea)
	{
		if (node->Position == newNodePos)
			return node;
	}
	return nullptr;
}

bool Pathfinding::CheckAllNodesCompleted()
{
	for (auto node : nodeList.examinatedNodeArea)
	{
		if (!node->NodeCompleted)
			return false;
	}
	return true;
}


int Pathfinding::GetHCost(Engine::Vector2D newNodePos, Engine::Vector2D targetPos)
{
	int x = fabsf(targetPos.X - newNodePos.X);
	int y = fabsf(targetPos.Y - newNodePos.Y);
	
	if (x < y)
		return (y - x) + (hypotf(x, x));
	else
		return (x - y) + (hypotf(y, y));
}
