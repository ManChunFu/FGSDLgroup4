#include "Map.h"
#include <TextureManager.h>

namespace Engine
{
	class Collider;
}


// temporarily using to generate map

int mainLevel[20][25] 
{
	{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

};
Map::Map()
{
	sandFloor0 = Engine::TextureManager::GetTexture("Ground01");
	sandFloor1 = Engine::TextureManager::GetTexture("Ground02");
	sandFloor2 = Engine::TextureManager::GetTexture("Ground03");
	sandFloor3 = Engine::TextureManager::GetTexture("Ground04");
	Obstcl0 = Engine::TextureManager::GetTexture("Obstacle01");
	
	LoadMap(mainLevel);
	
	sourceRect.x = sourceRect.y = 0;
	sourceRect.w = destRect.w = 32;
	sourceRect.h = destRect.h = 32;

	destRect.x = destRect.y = 0;

	ScaleX = 2;
	ScaleY = 2;
	
}


Map::~Map()
{
}

void Map::Update()
{
	Entity::Update();
}

void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;

	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			destRect.x = column * 32 * ScaleX;
			destRect.y = row * 32 * ScaleY;

			switch (type)
			{
			case 0:
				Engine::TextureManager::Draw(sandFloor0, sourceRect, destRect);
				break;
			case 1:
				Engine::TextureManager::Draw(sandFloor1, sourceRect, destRect);
				break;
			case 2:
				Engine::TextureManager::Draw(sandFloor2, sourceRect, destRect);
				break;
			case 3:
				Engine::TextureManager::Draw(sandFloor3, sourceRect, destRect);
				break;
			case 4:
				if (!obstacle)
				{
					obstacle = new Entity();
					sourceRect.x = sourceRect.y = 0;
					sourceRect.w = destRect.w = 32;
					sourceRect.h = destRect.h = 32;
					destRect.x = column * 32 * ScaleX;
					destRect.y = row * 32 * ScaleY;
					obstacle->position.X = column * 32 * ScaleX;;
					obstacle->AddSprite("Obstacle01");
					obstacle->AddCollider("Obstacle01", true);
				}
				
				break;

			default:
				break;
			}
		}
	}
}
