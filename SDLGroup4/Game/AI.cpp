#include "AI.h"
#include <random>
#include <ctime>
#include <time.h>
#include "NodeList.h"

bool AI::EnterDangerZone(float radiusLimit, Engine::Vector2D position, Engine::Vector2D targetPosition)
{
	return (hypotf(fabsf(targetPosition.X - position.X), fabsf(targetPosition.Y - position.Y)) <= radiusLimit);
}

std::vector<Engine::Vector2D> AI::pathFinding(Engine::Vector2D targetPosition, Engine::Vector2D startPosition)
{
	nodelist = new NodeList(targetPosition, startPosition);
	nodelist->GetPath();
	return nodelist->Path;
		
}

Engine::Vector2D AI::RandomMovement()
{
	std::mt19937 generator;
	generator.seed(std::time(0));
	
	float X = (std::uniform_int_distribution<uint32_t>(1, 1439))(generator);
	float Y = (std::uniform_int_distribution<uint32_t>(1, 899))(generator);

	position.X = X;
	position.Y = Y;
	return position;
}



