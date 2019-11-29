#include "Obstacle.h"
#include "TextureManager.h"


Obstacle::~Obstacle()
{
}

void Obstacle::Update()
{
	Engine::Entity::Update();
	collider->solid = true;
	collider->movable = false;

	destRect.x = position.X; destRect.y = position.Y;
	destRect.w = ScaleX * sourceRect.w;
	destRect.h = ScaleY * sourceRect.h;
}


void Obstacle::OnCollisionEnter(Engine::Collider* other)
{

}
