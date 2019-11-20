#include "AI.h"
#include <random>
#include <ctime>
#include <time.h>
#include "NodeList.h"
#include <iostream>

bool AI::EnterDangerZone(float radiusLimit, Engine::Vector2D position, Engine::Vector2D targetPosition)
{
	return (hypotf(fabsf(targetPosition.X - position.X),fabsf(targetPosition.Y - position.Y)) <= radiusLimit);
}

std::vector<Engine::Vector2D> AI::pathFinding(Engine::Vector2D targetPosition, Engine::Vector2D startPosition)
{
	int targetPosIntX = (int)targetPosition.X;
	int targetPosIntY = (int)targetPosition.Y;
	int startPosIntX = (int)startPosition.X;
	int startPosIntY = (int)startPosition.Y;
	Engine::Vector2D targetPosInt;
	targetPosInt.X = targetPosIntX;
	targetPosInt.Y = targetPosIntY;
	Engine::Vector2D startPosInt;
	startPosInt.X = startPosIntX;
	startPosInt.Y = startPosIntY;
	nodelist = new NodeList(targetPosInt, startPosInt);
	std::vector<Engine::Vector2D> list = nodelist->GetPath(); //need to give return a list

	delete nodelist;
	return list;
}

Engine::Vector2D AI::RandomMovement()
{
	float x = (rand() % 7) - 3;
	float y = (rand() % 7) - 3;
	
	Engine::Vector2D position;
	position.X = x;
	position.Y = y;
	return position;
}




