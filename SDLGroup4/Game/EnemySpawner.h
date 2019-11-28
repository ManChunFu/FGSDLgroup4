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
	void Update();
	float WizardSpawnRate = 40;
	float TrollSpawnRate = 10;
	bool SpawningTrolls = true;
	bool SpawningWizards = true;
private:
	Engine::Vector2D RandomPos();
	Enemy* enemy;
	Wizard* wizard;
	float wizardTimer = 0;
	float trollTimer = 0;
};

