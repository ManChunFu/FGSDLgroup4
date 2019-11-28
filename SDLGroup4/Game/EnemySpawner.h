#pragma once
class Enemy;
class Wizard;
namespace Engine 
{
	class Vector2D;
}
class EnemySpawner
{
public:
	void SpawnTroll();
	void SpawnWizard();
	void SpawnKnight();
	void Update();
	void Reset();
	float WizardSpawnRate = 40;
	float TrollSpawnRate = 10;
	float KnightSpawnRate = 10;
	bool SpawningTrolls = false;
	bool SpawningWizards = false;
	bool SpawningKnights = true;
private:
	Engine::Vector2D RandomPos();
	Enemy* enemy;
	Wizard* wizard;
	float wizardTimer = 0;
	float trollTimer = 0;
	float knightTimer = 9;
};

