#pragma once
#include <Vector2D.h>
#include <Vector>

class AI
{
public:
	bool EnterDangerZone(float radiusLimit, float xPos, float yPos, float targetXPos, float targetYPos);
	std::vector<Engine::Vector2D> pathFinding(float targetXPos, float targetYPos, float startXPos, float startYpos);

private:
	
	
};

