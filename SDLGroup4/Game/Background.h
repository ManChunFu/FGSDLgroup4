#pragma once
#include <Entity.h>
#include <string>
#include <TextureManager.h>
class Background : public Engine::Entity
{
public:
	Background(std::string name) : Engine::Entity()
	{
		AddSprite(name);
	};
};

