#include "TestBullet.h"
#include <GameTime.h>
void Bullet::Update()
{
	Engine::Vector2D movement;
	movement.Y = -1 * speed * Engine::GameTime::DeltaTime();
	position.X += movement.X;
	lifeSpan -= Engine::GameTime::DeltaTime();
	if (lifeSpan < 0) {
		Engine::Scene::ActiveScene->Destroy(this);
	}
	Entity::Update();
}
