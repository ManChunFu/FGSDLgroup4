#pragma once
#include <TextureManager.h>
#include <SoundManager.h>
class Setup
{
public:
	static void Sprites() 
	{
		Engine::TextureManager::AddTexture("MenuBackground", "Assets/Sprites/DarkForest/main_backgroundCastle.png");
		Engine::TextureManager::AddTexture("GameOverBackground", "Assets/Sprites/DarkForest/main_background4.png");
		Engine::TextureManager::AddTexture("Wizard", "Assets/Sprites/Enemy/Wizard/sprite.png");
		Engine::TextureManager::AddTexture("WizardIdle", "Assets/Sprites/Enemy/Wizard/IDLE.png");
		Engine::TextureManager::AddTexture("WizardWalk", "Assets/Sprites/Enemy/Wizard/WALK.png");
		Engine::TextureManager::AddTexture("WizardAttack", "Assets/Sprites/Enemy/Wizard/ATTACK1.png");
		Engine::TextureManager::AddTexture("WizardHurt", "Assets/Sprites/Enemy/Wizard/HURT.png");
		Engine::TextureManager::AddTexture("WizardDie", "Assets/Sprites/Enemy/Wizard/DIE.png");
		Engine::TextureManager::AddTexture("Knight", "Assets/Sprites/Enemy/Knight/sprite1.png");
		Engine::TextureManager::AddTexture("KnightIdle", "Assets/Sprites/Enemy/Knight/IDLE.png");
		Engine::TextureManager::AddTexture("KnightWalk", "Assets/Sprites/Enemy/Knight/WALK.png");
		Engine::TextureManager::AddTexture("KnightRun", "Assets/Sprites/Enemy/Knight/RUN.png");
		Engine::TextureManager::AddTexture("KnightAttack", "Assets/Sprites/Enemy/Knight/ATTACK.png");
		Engine::TextureManager::AddTexture("KnightDie", "Assets/Sprites/Enemy/Knight/DIE1.png");
		Engine::TextureManager::AddTexture("KnightHurt", "Assets/Sprites/Enemy/Knight/HURT.png");
		Engine::TextureManager::AddTexture("Enemy", "Assets/Sprites/Enemy/sprite.png");
		Engine::TextureManager::AddTexture("Hp", "Assets/Sprites/Player/hp.png");
		Engine::TextureManager::AddTexture("EnemyIdle", "Assets/Sprites/Enemy/IDLE1.png");
		Engine::TextureManager::AddTexture("EnemyWalk", "Assets/Sprites/Enemy/WALK.png");
		Engine::TextureManager::AddTexture("EnemyRun", "Assets/Sprites/Enemy/RUN.png");
		Engine::TextureManager::AddTexture("EnemyAttack", "Assets/Sprites/Enemy/ATTACK.png");
		Engine::TextureManager::AddTexture("EnemyHurt", "Assets/Sprites/Enemy/HURT.png");
		Engine::TextureManager::AddTexture("EnemyDie", "Assets/Sprites/Enemy/DIE1.png");
		Engine::TextureManager::AddTexture("Player", "Assets/Sprites/Player/sprite.png");
		Engine::TextureManager::AddTexture("PlayerIdle", "Assets/Sprites/Player/IDLE.png");
		Engine::TextureManager::AddTexture("PlayerRun", "Assets/Sprites/Player/RUN.png");
		Engine::TextureManager::AddTexture("PlayerAttack", "Assets/Sprites/Player/ATTACK.png");
		Engine::TextureManager::AddTexture("PlayerHurt", "Assets/Sprites/Player/HURT.png");
		Engine::TextureManager::AddTexture("PlayerDie", "Assets/Sprites/Player/DIE1.png");
		Engine::TextureManager::AddTexture("PlayerBlink", "Assets/Sprites/Player/BLINK.png");
		Engine::TextureManager::AddTexture("IceBallSprite", "Assets/Sprites/Player/ICEBALLSprite.png");
		Engine::TextureManager::AddTexture("IceBall", "Assets/Sprites/Player/ICEBALL1.png");
		Engine::TextureManager::AddTexture("FireBall", "Assets/Sprites/player/FIREBALL1.png");
		Engine::TextureManager::AddTexture("Ground01", "Assets/Sprites/floor_sand_rock_0.png");
		Engine::TextureManager::AddTexture("Ground02", "Assets/Sprites/floor_sand_rock_1.png");
		Engine::TextureManager::AddTexture("Ground03", "Assets/Sprites/floor_sand_rock_2.png");
		Engine::TextureManager::AddTexture("Stone", "Assets/Sprites/Enviroment/stone_brick_1.png");
		Engine::TextureManager::AddTexture("Border", "Assets/Sprites/Enviroment/bars_red_2.png");
		Engine::TextureManager::AddTexture("Obstacle01", "Assets/Sprites/Enviroment/silver_wall.png");
		Engine::TextureManager::AddTexture("TeleportCooldown", "Assets/Buttons/PNG/shiny/1.png");
	}
	static void Sounds() 
	{
		Engine::SoundManager::AddSoundEffect("Hurt", "Assets/Sounds/Wounded.wav");
		Engine::SoundManager::AddSoundEffect("Shoot", "Assets/Sounds/Shoot.wav");
		Engine::SoundManager::AddSoundEffect("EnemyAttack", "Assets/Sounds/EnemyAttack.wav");
		Engine::SoundManager::AddSoundEffect("TrollHurt", "Assets/Sounds/TrollHurt.wav");
		Engine::SoundManager::AddSoundEffect("TrollDeath", "Assets/Sounds/TrollDeath.wav");
		Engine::SoundManager::AddSoundEffect("KnightHurt", "Assets/Sounds/KnightHurt.wav");
		Engine::SoundManager::AddSoundEffect("KnightAttack", "Assets/Sounds/KnightAttack.wav");
		Engine::SoundManager::AddSoundEffect("Teleport", "Assets/Sounds/TeleportSound.wav");
		Engine::SoundManager::AddSoundEffect("KnightDeath", "Assets/Sounds/KnightDeath.wav");
		Engine::SoundManager::AddSoundEffect("WizardCastSpell", "Assets/Sounds/WizardMagic.wav");
		Engine::SoundManager::AddSoundEffect("WizardHurt", "Assets/Sounds/WizardHurt.wav");
		Engine::SoundManager::AddSoundEffect("WizardDeath", "Assets/Sounds/WizardDeath.wav");
		
	}

};