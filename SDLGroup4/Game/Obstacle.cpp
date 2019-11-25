#include "Obstacle.h"
#include "TextureManager.h"


Obstacle::~Obstacle()
{
}

void Obstacle::Update()
{
	Engine::Entity::Update();
	collider->solid = true;
}


void Obstacle::OnCollisionEnter(Engine::Collider* other)
{

}
