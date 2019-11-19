#include "NodeList.h"
#include "Node.h"


NodeList::NodeList(Engine::Vector2D targetPos, Engine::Vector2D startPos) ://, std::vector<Engine::Vector2D*> obstacleList) :
	targetPos(targetPos), startPos(startPos) {}//, obstacleList(obstacleList){}

NodeList::~NodeList()
{
	for (auto examinatedNode : examinatedNodeArea)
		delete examinatedNode;
	examinatedNodeArea.clear();
	// todo delete all lists ( one list with all the nodes)
	for (auto workingNode : workingNodes)
		delete workingNode;
	workingNodes.clear();
	//closeNodes.clear();
}

std::vector<Engine::Vector2D> NodeList::GetPath()
{
	//std::vector<Engine::Vector2D> result;
	
	examinatedNodeArea.push_back(new Node(startPos, GetHCost(startPos, targetPos), nullptr));

	bool reachTarget = false;
	currentSmallestFCost = 1000;
	
	do 
	{
		SetWorkingNodes();

		for (Node* current : workingNodes)
		{
			if (current->Position == targetPos)
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
					(newMovePosDiagnoal.Y >= sceneSizeMinY && newMovePosDiagnoal.X <= sceneSizeMaxY))
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
	/*for (auto node : workingNodes)
		delete node;*/
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
	for (auto obstacle : obstacleList)
		return (obstacle == newNodePos);

	return false;
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


//void NodeList::MoveNodeToClose(Node* node)
//{
//	closeNodes.push_back(node);
//	for (int index = 0; index < examinatedNodeArea.size(); index++)
//	{
//		if (node->Position == examinatedNodeArea[index]->Position)
//			examinatedNodeArea.erase(examinatedNodeArea.begin() + index);
//	}
//}

int NodeList::GetHCost(Engine::Vector2D newNodePos, Engine::Vector2D targetPos)
{
	int x = fabsf(targetPos.X - newNodePos.X);
	int y = fabsf(targetPos.Y - newNodePos.Y);
	if (x < y)
		return (y - x) + (hypotf(x, x));
	else
		return (x - y) + (hypotf(y, y));
}
