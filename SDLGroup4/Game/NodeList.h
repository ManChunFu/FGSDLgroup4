#pragma once
#include <Vector2D.h>
#include <vector>
#include "Node.h"

class NodeList 
{
public:
	NodeList(Engine::Vector2D targetPos, Engine::Vector2D startPos);
	~NodeList();

	std::vector<Engine::Vector2D> GetPath();
	void SetNewTargetPos(Engine::Vector2D targetPos) { this->targetPos = targetPos; }
	void SetNewStartPos(Engine::Vector2D startPos) { this->targetPos = startPos; }

	
private:
	int GetHCost(Engine::Vector2D newNodePos, Engine::Vector2D targetPos);
	void SetWorkingNodes();
	bool CheckObstacle(Engine::Vector2D newNodePos);
	Node* CheckExistingNode(Engine::Vector2D newNodePos);
	bool CheckAllNodesCompleted();

	std::vector<Node*> examinatedNodeArea;
	std::vector<Node*> workingNodes;
	std::vector<Node*> closeNodes;
	std::vector<Engine::Vector2D> Path;
	std::vector<Engine::Vector2D> obstacleList;

	int miniFCost;
	int miniHCostOfAllMiniFCosts;
	int currentSmallestFCost;
	const int sceneSizeMinX = 0, sceneSizeMinY = 0, sceneSizeMaxX = 1440, sceneSizeMaxY = 900;
	
	Engine::Vector2D targetPos;
	Engine::Vector2D startPos; 
	
	Engine::Vector2D moveByStraightLine[4] =
	{
		Engine::Vector2D(-3.0f, 0.0f), //left
		Engine::Vector2D(0.0f, -3.0f), //up
		Engine::Vector2D(3.0f, 0.0f), //right
		Engine::Vector2D(0.0f, 3.0f) // down
	};
	Engine::Vector2D moveByDiagnoalLine [4] =
	{
		Engine::Vector2D(-3.0f, -3.0f), //top left corner
		Engine::Vector2D(3.0f, -3.0f), //top right corner
		Engine::Vector2D(3.0f, 3.0f),//bottom right corner
		Engine::Vector2D(-3.0f, 3.0f) // bottom left corner
	};
	
};
