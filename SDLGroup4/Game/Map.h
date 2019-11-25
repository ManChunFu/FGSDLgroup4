#pragma once
#include <SDL.h>
#include <Entity.h>
#include <TextureManager.h>
#include "MainScene.h"
#include <vector>
#include <unordered_map>
namespace Engine
{ 
	
}
class Map : public Engine :: Entity 
{
public:
	Engine::Entity* obstacle;
	Map();
	~Map();

	void Update() override;
	void LoadMap(int arr [20][25]);
	void DrawMap();
private:

	
	SDL_Texture* sandFloor0;
	SDL_Texture* sandFloor1;
	SDL_Texture* sandFloor2;
	SDL_Texture* sandFloor3;
	SDL_Texture* Obstcl0;
	int map[20][25]; //tileholder 

};