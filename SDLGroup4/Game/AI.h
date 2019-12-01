#pragma once
#include <Vector2D.h>
#include <Vector>

class Pathfinding;
class AI 
{
public:
	bool EnterDangerZone(float radiusLimit, Engine::Vector2D position, Engine::Vector2D targetPosition);
	std::vector<Engine::Vector2D> CallPathFinding(Engine::Vector2D targetPosition, Engine::Vector2D startPosition);
	Engine::Vector2D RandomMovement();
	float GetDistance(Engine::Vector2D position, Engine::Vector2D targetPosition);

private:
	Pathfinding* pathfinding;

};

