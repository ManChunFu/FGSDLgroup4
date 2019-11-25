#pragma once
#include <Entity.h>
#include <Scene.h>
#include "Collider.h"
#include "MainScene.h"

namespace Engine 
{
	class Collider;
	class CollisionManager;
}


class Obstacle : public Engine::Entity
{
public:
	Obstacle(): Engine::Entity()
	{
		Engine::TextureManager::GetTexture("Obstacle01");
	};
	~Obstacle();

	void Update() override;
	

private:

	SDL_Texture* Obstcl0;
	int _posX;
	int _posY;
	Engine::Collider* collid;
	void OnCollisionEnter(Engine::Collider* other) override;

};
