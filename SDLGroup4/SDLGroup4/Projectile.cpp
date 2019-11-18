#include "Projectile.h"
#include "Vector2D.h"
#include "GameTime.h"

namespace Engine
{
	void Projectile::Update()
	{

	
		position.X +=  dirX * shootX * Engine::GameTime::DeltaTime();
		position.Y += dirY * shootY * Engine::GameTime::DeltaTime();

		if (lifeSpan < 0)
		{
			Engine::AbstractionModule::ActiveScene->Destroy(this);
		}
		Entity::Update();
	}

}