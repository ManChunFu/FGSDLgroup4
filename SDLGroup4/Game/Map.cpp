#include "Map.h"
#include <TextureManager.h>
#include "Setup.h"
#include "Obstacle.h"
#include "MainScene.h"


namespace Engine
{
	class Collider;
}


// fix this shit (um)

int mainLevel[20][25] 
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},
	{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	 
};
Map::Map()
{
	redTiles0 = Engine::TextureManager::GetTexture("Ground03");
	stonefloor = Engine::TextureManager::GetTexture("Stone");
	/*sandFloor1 = Engine::TextureManager::GetTexture("Ground02");
	sandFloor2 = Engine::TextureManager::GetTexture("Ground03");*/
	//sandFloor3 = Engine::TextureManager::GetTexture("Ground04");
	
	
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
			destRect.x = column * 32 * ScaleX;
			destRect.y = row * 32 * ScaleY;

			if (arr[row][column] == 1)
			{
				
				MainScene::mainScene->obstacle.push_back(new Obstacle());
				MainScene::mainScene->obstacle[MainScene::mainScene->obstacle.size() - 1]->AddSprite("Obstacle01");
				MainScene::mainScene->obstacle[MainScene::mainScene->obstacle.size() - 1]->AddCollider("Obstacle01", true);
				MainScene::mainScene->obstacle[MainScene::mainScene->obstacle.size() - 1]->ScaleX = 2;
				MainScene::mainScene->obstacle[MainScene::mainScene->obstacle.size() - 1]->ScaleY = 2;
				MainScene::mainScene->obstacle[MainScene::mainScene->obstacle.size() - 1]->position = { (float)column *64, (float)row * 64};
			}

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


			//if (map[column][row] == 0)
			//{
			//	Engine::TextureManager::Draw(stonefloor, sourceRect, destRect);
			//}
			switch (type)
			{
			case 0:
				Engine::TextureManager::Draw(stonefloor, sourceRect, destRect);
				break;
			/*case 1:
				Engine::TextureManager::Draw(redTiles1, sourceRect, destRect);
				break;
			case 2:
				Engine::TextureManager::Draw(sandFloor2, sourceRect, destRect);
				break;
			case 3:
				Engine::TextureManager::Draw(sandFloor3, sourceRect, destRect);*/
				break;
			default:
				break;
			}
		}
	}
}
