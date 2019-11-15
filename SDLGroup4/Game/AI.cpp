#include "AI.h"
#include <math.h>

bool AI::EnterDangerZone(float radiusLimit, float xPos, float yPos, float targetXPos, float targetYPos)
{
	return (hypotf(fabsf(targetXPos - xPos), fabsf(targetYPos - yPos)) <= radiusLimit);
}

std::vector<Engine::Vector2D> AI::pathFinding(float targetXPos, float targetYPos, float startXPos, float startYpos)
{

	return std::vector<Engine::Vector2D>();
}
