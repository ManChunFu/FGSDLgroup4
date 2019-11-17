#pragma once
#include <Vector2D.h>
#include <Vector>

class AI 
{
public:
	bool EnterDangerZone(float radiusLimit, Engine::Vector2D position, Engine::Vector2D targetPosition);
	std::vector<Engine::Vector2D> pathFinding(Engine::Vector2D targetPosition, Engine::Vector2D startPosition);
	void RandomMovement();

private:
	float positionX, positionY;
};

