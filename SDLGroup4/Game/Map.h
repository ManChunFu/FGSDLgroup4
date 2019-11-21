#pragma once
#include <SDL.h>
#include <Entity.h>
#include <TextureManager.h>
#include "MainScene.h"

namespace Engine
{ }
class Map : public Engine :: Entity 
{
public:
	Map();
	~Map();

	void Update() override;
	void LoadMap(int arr [20][25]);
	void DrawMap();
private:

	SDL_Rect srcRect, destRect;
	SDL_Texture* sandFloor0;
	SDL_Texture* sandFloor1;
	SDL_Texture* sandFloor2;
	SDL_Texture* sandFloor3;

	int map[20][25]; //tileholder 

};