#pragma once
#include <Entity.h>
#include <Scene.h>
//#include <InputManager.h>

namespace Engine 
{
	class InputManager;
	class Animator;
	class CollisionManager;
	class Vector2D;
	class TextureManager;
}

class Player : public Engine :: Entity
{
public:
	Entity* player;

	Player(Engine::InputManager* input, int playerHP, std::string path, int height, int width, int xpos, int ypos, Engine::Scene* scene) :
		Engine::Entity(path, height, width, xpos, ypos, scene) { hitPoint = playerHP; inputManager = input; };


	void Update() override;
	void Render() override;

	float moveSpeed = 10.0f;

private:
	Engine::InputManager* inputManager = nullptr;
	Engine::Collider* collider = nullptr;
	Engine::Animator* anim = nullptr;

	int hitPoint;
	float position;


	
	void MovePlayer();
	

};

