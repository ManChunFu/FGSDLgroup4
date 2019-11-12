#pragma once
#include <vector>
#include "Canvas.h"
namespace Engine 
{
	class GameElement;
	class UIManager
	{
	public:
		static std::vector<Canvas*> Scenes;
		static void Initialize();
		static void Initialize(SDL_Color color, GameElement base);
		static void AddObjectsToScene(int scene, std::vector<GameElement*> childObjects);
		static void Render() { Scenes[ActiveScene]->Render(); }
		static int CreateScene(SDL_Color color, GameElement base) { Scenes.push_back(new Canvas(color, base)); return Scenes.size(); }
		static void Update() {}
		static void Shutdown() 
		{
			for (auto canvas : Scenes) 
			{
				if (canvas)
				{
					canvas->Close();
					delete canvas;
					canvas = nullptr;
				}
			}
		}
		static int ActiveScene;
	};
}

