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
	return list;
}

Engine::Vector2D AI::RandomMovement()
{
	std::mt19937 generator;
	generator.seed(std::time(0));

	float X = (std::uniform_int_distribution<uint32_t>(0, 4))(generator); 
	float Y = (std::uniform_int_distribution<uint32_t>(0, 4))(generator);

	Engine::Vector2D position;
	position.X = (X - 2); // to get minus value
	position.Y = (Y - 2);
	return position;
}




