#pragma once
#include <SDL.h>
#include <Entity.h>
#include <TextureManager.h>
#include "MainScene.h"

namespace Engine
{ 
	
}

class Map : public Engine :: Entity 
{
public:
	/*Engine::Entity* obstacle;*/
	Map();
	~Map();

	void Update() override;
	void LoadMap(int arr [20][25]);
	void DrawMap();
private:
	
	SDL_Texture* stonefloor;
	int map[20][25]; //tileholder 
};