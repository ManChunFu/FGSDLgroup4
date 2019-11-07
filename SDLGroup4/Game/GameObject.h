#pragma once

#include <Entity.h>
#include <SDL.h>



class GameObject : public Engine::Entity
{
public:
	
	void Update() override { Engine::Entity::Update(); }

};

