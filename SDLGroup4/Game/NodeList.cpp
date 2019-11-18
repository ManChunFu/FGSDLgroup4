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

	
	workingNodes.clear();
	closeNodes.clear();
}

std::vector<Engine::Vector2D> NodeList::GetPath()
{
	std::vector<Engine::Vector2D> result;
	examinatedNodeArea.push_back(new Node(startPos, GetHCost(startPos, targetPos), nullptr));

	bool reachTarget = false;
	currentSamllestFCost = 1000;
	
	do 
	{
		SetWorkingNodes();

		for (Node* current : workingNodes)
		{
			if (current->Position == targetPos)
			{
				reachTarget = true;
				Node* nodesToTarget = current;
				Path.push_back(current->Position);

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
			MoveNodeToClose(current);
		}
	} while (!reachTarget);

	return result;
}


void NodeList::SetWorkingNodes()
{
	workingNodes.empty();

	int arrayCount = examinatedNodeArea.size();
	int miniFCost = 0;
	if (arrayCount < 1)
	{
		miniFCost = NULL;
		return;
	}
		
	for (auto node : examinatedNodeArea)
	{
		if (miniFCost == NULL || node->FCost < miniFCost)
			miniFCost = (int)node->FCost;
	}	

	if (miniFCost > currentSamllestFCost)
	{
		for (auto node : examinatedNodeArea)
		{
			if (node->FCost == miniFCost)
				workingNodes.push_back(node);
		}
	}	
	else
	{	
		currentSamllestFCost = (int)miniFCost;
		int miniHCostOfAllMiniFCosts = NULL;

		for (auto node : examinatedNodeArea)
		{
			if (node->FCost == miniFCost)
				if (miniHCostOfAllMiniFCosts == NULL || node->HCost < miniHCostOfAllMiniFCosts)
					miniHCostOfAllMiniFCosts = (int)node->HCost;
		}

		for (auto node : examinatedNodeArea)
		{
			if (node->FCost == miniFCost && node->HCost == miniHCostOfAllMiniFCosts)
				workingNodes.push_back(node);
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


void NodeList::MoveNodeToClose(Node* node)
{
	closeNodes.push_back(node);
	for (int index = 0; index < examinatedNodeArea.size(); index++)
	{
		if (node->Position == examinatedNodeArea[index]->Position)
			examinatedNodeArea.erase(examinatedNodeArea.begin() + index);
	}
}

float NodeList::GetHCost(Engine::Vector2D newNodePos, Engine::Vector2D targetPos)
{
	float x = fabsf(targetPos.X - newNodePos.X);
	float y = fabsf(targetPos.Y - newNodePos.Y);
	if (x < y)
		return (y - x) + (hypotf(x, x));
	else
		return (x - y) + (hypotf(y, y));
}
