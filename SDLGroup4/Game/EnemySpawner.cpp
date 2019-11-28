#include "EnemySpawner.h"
#include "Enemy.h"
#include "Wizard.h"
#include <Vector2D.h>
#include <GameTime.h>
void EnemySpawner::SpawnTroll()
{
	enemy = new Enemy(4, true);
	enemy->position = RandomPos();
}

void EnemySpawner::SpawnWizard()
{
	wizard = new Wizard(8);
	wizard->position = RandomPos();
}

void EnemySpawner::SpawnKnight()
{
	enemy = new Enemy(6, false);
	enemy->position = RandomPos();
}

void EnemySpawner::Update()
{
	if (SpawningWizards && wizardTimer > WizardSpawnRate)
	{ 
		SpawnWizard(); 
		wizardTimer = 0;
	}
	else if (SpawningWizards) wizardTimer += Engine::GameTime::DeltaTime();
	if (SpawningTrolls && trollTimer > TrollSpawnRate)
	{ 
		SpawnTroll(); 
		trollTimer = 0;
	}
	else if (SpawningTrolls) trollTimer += Engine::GameTime::DeltaTime();
	if (SpawningKnights && knightTimer > KnightSpawnRate)
	{ 
		SpawnKnight(); 
		knightTimer = 0;
	}
	else if (SpawningTrolls) knightTimer += Engine::GameTime::DeltaTime();
}

void EnemySpawner::Reset()
{
	wizardTimer = 0;
	trollTimer = 0;
}

Engine::Vector2D EnemySpawner::RandomPos()
{
	float x = rand() % 800 + 100;
	float y = rand() % 450 + 100;

	Engine::Vector2D position;
	position.X = x;
	position.Y = y;
	return position;
}
