#pragma once
#include <Entity.h>
#include <Scene.h>
//#include <InputManager.h>
class Bullet;
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
	Player(Engine::InputManager* input, int playerHP) : Engine::Entity() 
	{ hitPoint = playerHP; inputManager = input; };


	void Update() override;

	float moveSpeed = 500.0f;

private:
	Engine::InputManager* inputManager = nullptr;
	Engine::Collider* collider = nullptr;
	Engine::Animator* anim = nullptr;

	int hitPoint = 0;
	Bullet* bullet = nullptr;

	
	void MovePlayer();
	


	// Inherited via Entity
	virtual void OnCollisionEnter(Engine::Collider* other) override;

};

