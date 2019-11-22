#pragma once
#include <Entity.h>
#include <Scene.h>

class Obsticale : public Engine::Entity
{
public:
	Obsticale() : Engine::Entity()
	{
	}

	void Update() override;

private:
	void OnCollisionEnter(Engine::Collider* other) override;
};
