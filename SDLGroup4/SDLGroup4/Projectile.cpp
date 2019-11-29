#include "Projectile.h"
#include "Vector2D.h"
#include "GameTime.h"

namespace Engine
{
	void Projectile::Update()
	{

	
		position.X +=  dirX * shootX * Engine::GameTime::DeltaTime();
		position.Y += dirY * shootY * Engine::GameTime::DeltaTime();
		if(position.X < 0)Engine::Scene::ActiveScene->Destroy(this);
		if(position.Y < 0)Engine::Scene::ActiveScene->Destroy(this);
		if(position.X > 1440)Engine::Scene::ActiveScene->Destroy(this);
		if(position.Y > 900)Engine::Scene::ActiveScene->Destroy(this);
		if (lifeSpan < 0)
		{
			Engine::Scene::ActiveScene->Destroy(this);
		}
		Entity::Update();
	}

	void Projectile::OnCollisionEnter(Collider* other)
	{
		if (affectsEnemies) 
		{
		  if(other->tag != "Player" ) 
			 Scene::ActiveScene->Destroy(this);
		}
		else 
		{
			if (other->tag != "Enemy")
				Scene::ActiveScene->Destroy(this);
		}
	}

}