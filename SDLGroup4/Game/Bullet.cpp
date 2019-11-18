#include "Bullet.h"
#include <Time.h>
void Bullet::Update()
{
	Engine::Vector2D movement;
	movement.Y = -1 * speed * Engine::Time::DeltaTime();
	position.X += movement.X;
	lifeSpan -= Engine::Time::DeltaTime();
	if (lifeSpan < 0) {
		Engine::AbstractionModule::ActiveScene->Destroy(this);
	}
	Entity::Update();
}
