#pragma once
#include <Vector2D.h>
#include <vector>
#include "Node.h"
#include "NodeList.h"

class NodeList;
class Pathfinding 
{
public:
	Pathfinding(Engine::Vector2D targetPos, Engine::Vector2D startPos);
	~Pathfinding();

	std::vector<Engine::Vector2D> GetPath();
	void SetNewTargetPos(Engine::Vector2D targetPos) { this->targetPos = targetPos; }
	void SetNewStartPos(Engine::Vector2D startPos) { this->targetPos = startPos; }
	
private:
	NodeList nodeList;
	std::vector<Engine::Vector2D> Path;

	int GetHCost(Engine::Vector2D newNodePos, Engine::Vector2D targetPos);
	void SetWorkingNodes();
	bool CheckObstacle(Engine::Vector2D newNodePos);
	Node* CheckExistingNode(Engine::Vector2D newNodePos);
	bool CheckAllNodesCompleted();

	const int sceneSizeMinX = 0, sceneSizeMinY = 0, sceneSizeMaxX = 1440, sceneSizeMaxY = 900;
	
	Engine::Vector2D targetPos;
	Engine::Vector2D startPos; 
	
	/*Move 3 steps instead of 1 step for solving lag issue when many enemies call this function*/
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
