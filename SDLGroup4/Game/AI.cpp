#include "AI.h"
#include <random>
#include <ctime>
#include <time.h>

bool AI::EnterDangerZone(float radiusLimit, Engine::Vector2D position, Engine::Vector2D targetPosition)
{
	return (hypotf(fabsf(targetPosition.X - position.X), fabsf(targetPosition.Y - position.Y)) <= radiusLimit);
}

std::vector<Engine::Vector2D> AI::pathFinding(Engine::Vector2D targetPosition, Engine::Vector2D startPosition)
{
	return std::vector<Engine::Vector2D>();
}

void AI::RandomMovement()
{
	std::mt19937 generator;
	generator.seed(std::time_t(0));
	
	//positionX = (std::uniform_int_distribution<uint32_t>(1, 1439))(generator);
	

	/*position->X += inputManager->GetAxis("Horizontal") * moveSpeed * Engine::Time::DeltaTime();
	position->Y += inputManager->GetAxis("Vertical") * moveSpeed * Engine::Time::DeltaTime();*/
}



