#pragma once
class Enemy;
class Wizard;
class EnemySpawner
{
public:
	void SpawnTroll();
	void SpawnWizard();
	void Update();
	float WizardSpawnRate = 50;
	float TrollSpawnRate = 20;
	bool SpawningTrolls = true;
	bool SpawningWizards = true;
private:
	void RandomPos();
	Enemy* enemy;
	Wizard* wizard;
	float wizardTimer = 50;
	float trollTimer = -1;
};

