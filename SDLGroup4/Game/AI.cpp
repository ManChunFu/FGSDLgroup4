#include "AI.h"
#include <random>
#include <ctime>
#include <time.h>
#include "Pathfinding.h"
#include <iostream>

bool AI::EnterDangerZone(float radiusLimit, Engine::Vector2D position, Engine::Vector2D targetPosition)
{
	return (hypotf(fabsf(targetPosition.X - position.X),fabsf(targetPosition.Y - position.Y)) <= radiusLimit);
}

std::vector<Engine::Vector2D> AI::CallPathFinding(Engine::Vector2D targetPosition, Engine::Vector2D startPosition)
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
	pathfinding = new Pathfinding(targetPosInt, startPosInt);
	std::vector<Engine::Vector2D> list = pathfinding->GetPath(); 

	delete pathfinding;
	return list;
}

Engine::Vector2D AI::RandomMovement()
{
	float x = (rand() % 3) - 1;
	float y = (rand() % 3) - 1;
	
	Engine::Vector2D position;
	position.X = x;
	position.Y = y;
	return position;
}

float AI::GetDistance(Engine::Vector2D position, Engine::Vector2D targetPosition)
{
	float distance = _hypotf(fabsf(targetPosition.X - position.X), fabsf(targetPosition.Y - position.Y));
	return distance;
}




