#pragma once
#include <Entity.h>
#include <string>
#include <Vector2D.h>

namespace Engine
{
	class InputManager;
}
class Enemy : public Engine::Entity
{
public:
	Enemy(std::string& spritePath, int width, int height, float xPos, float yPos);

	float speed = 100.0f;

	void Update() override;
	
	

private:
	Engine::InputManager* inputManager = nullptr;
	Engine::Vector2D* position;
	void MovePlayer(float deltaTime);

};

