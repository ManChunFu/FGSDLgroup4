#pragma once
#include "Entity.h"
#include <string>
#include "Vector2D.h"



	
	class Scene;
	class InputManager;



	class Projectile : public Engine :: Entity
{
public:
	Projectile(InputManager* input, std::string path, int height, int width, int xpos, int ypos, Scene* scene) : 
		Engine::Entity() { shootX = xpos; shootY = ypos; };

	void Update() override;
	void Render() override;

private:
	int shootX;
	int shootY;

	float projectileLife = 5.f;


};