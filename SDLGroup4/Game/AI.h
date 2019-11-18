#pragma once
#include <Vector2D.h>
#include <Vector>

class NodeList;
class AI 
{
public:
	bool EnterDangerZone(float radiusLimit, Engine::Vector2D position, Engine::Vector2D targetPosition);
	std::vector<Engine::Vector2D> pathFinding(Engine::Vector2D targetPosition, Engine::Vector2D startPosition);
	Engine::Vector2D RandomMovement();

private:
	Engine::Vector2D position;
	NodeList* nodelist;

	const int minScreen = 0;
	const int maxScreenWidth = 1440;
	const int maxScreenHight = 900;
};

