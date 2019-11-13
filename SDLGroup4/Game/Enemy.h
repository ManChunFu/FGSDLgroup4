#pragma once
#include <Entity.h>
#include <string>
#include <Vector2D.h>

namespace Engine
{
	class InputManager;
	class Collider;
	class Scene;
}
class Enemy : public Engine::Entity
{
public:
	Enemy(int hp, std::string& spritePath, int width, int height, float xPos, float yPos, Engine::Scene* scene) : 
		Engine::Entity(spritePath, width, height, xPos, yPos, scene)
	{
		hitpoint = hp;
	};


	float speed = 100.0f;
	int hitpoint;
	void OnCollisionEnter(Engine::Collider* other);
	void Update() override;
	
	

private:
	Engine::InputManager* inputManager = nullptr;
	Engine::Vector2D* position;
	void MovePlayer();

};

