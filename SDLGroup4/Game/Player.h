#pragma once
#include <Entity.h>
//#include <InputManager.h>

namespace Engine 
{
	class InputManager;
	class Animator;
}

class Player : public Engine :: Entity
{
public:
	Entity* player;

	Player(std::string path, int height, int width, int xpos, int ypos);


	void Update() override;
	void Render() override;

	float moveSpeed = 10.0f;

private:
	Engine::InputManager* inputManager = nullptr;
	Engine::Collider* collider = nullptr;
	Engine::Animator* anim = nullptr;


	
	void MovePlayer();
	

};

