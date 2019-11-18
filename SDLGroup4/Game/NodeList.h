#pragma once
#include <Vector2D.h>
#include <vector>
#include "Node.h"

class NodeList 
{
public:
	NodeList(Engine::Vector2D targetPos, Engine::Vector2D startPos);//, std::vector<Engine::Vector2D> obstacleList);
	~NodeList();

	std::vector<Engine::Vector2D> GetPath();
	void SetNewTargetPos(Engine::Vector2D targetPos) { this->targetPos = targetPos; }
	void SetNewStartPos(Engine::Vector2D startPos) { this->targetPos = startPos; }
	//void SetNewObstacleList(std::vector<Engine::Vector2D> obstacleList) { this->obstacleList = obstacleList; }

	std::vector<Engine::Vector2D> Path;	
	
private:
	float GetHCost(Engine::Vector2D newNodePos, Engine::Vector2D targetPos);
	void SetWorkingNodes();
	bool CheckObstacle(Engine::Vector2D newNodePos);
	Node* CheckExistingNode(Engine::Vector2D newNodePos);
	void MoveNodeToClose(Node* node);

	std::vector<Node*> examinatedNodeArea;
	std::vector<Node*> workingNodes;
	std::vector<Node*> closeNodes;
	std::vector<Engine::Vector2D> obstacleList;

	float currentSamllestFCost;
	const float sceneSizeMinX = 0, sceneSizeMinY = 0, sceneSizeMaxX = 1440, sceneSizeMaxY = 900;
	
	Engine::Vector2D targetPos;
	Engine::Vector2D startPos; 
	
	Engine::Vector2D moveByStraightLine[4] =
	{
		Engine::Vector2D(-1.0f, 0.0f), //left
		Engine::Vector2D(0.0f, -1.0f), //up
		Engine::Vector2D(1.0f, 0.0f), //right
		Engine::Vector2D(0.0f, 1.0f) // down
	};
	Engine::Vector2D moveByDiagnoalLine [4] =
	{
		Engine::Vector2D(-1.0f, -1.0f), //top left corner
		Engine::Vector2D(1.0f, -1.0f), //top right corner
		Engine::Vector2D(1.0f, 1.0f),//bottom right corner
		Engine::Vector2D(-1.0f, 1.0f) // bottom left corner
	};
	
};
