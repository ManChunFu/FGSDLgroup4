#include "TimedExplosive.h"
#include <GameTime.h>
void TimedExplosive::Update()
{
	if (lifeSpan < 0) 
	{
		if (explosionTimer == 2) 
		{
			this->AddCollider("Explosion");
			this->AddSprite("Explosion", 0.5f, 0.5f);
			position.X -= GetSpriteWidth() * 0.5f;
			position.Y -= GetSpriteHeight() * 0.5f;
		}
		explosionTimer -= Engine::GameTime::DeltaTime();
		if(explosionTimer < 0) Engine::Scene::ActiveScene->Destroy(this);
	}
	else lifeSpan -= Engine::GameTime::DeltaTime();
	Entity::Update();
}
