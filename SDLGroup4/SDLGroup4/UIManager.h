#pragma once
#include <vector>
#include "Canvas.h"
namespace Engine 
{
	class GameElement;
	class UIManager
	{
	public:
		static std::vector<Canvas*> ExistingCanvas;
		static void Initialize();
		static void Initialize(SDL_Color color, GameElement base);
		static void AddObjectsToScene(int scene, std::vector<GameElement*> childObjects);
		static void Render() { 
			if (ExistingCanvas.size() > 0)
				ExistingCanvas[ActiveCanvas]->Render(); 
		}
		static int CreateScene(SDL_Color color, GameElement base) { ExistingCanvas.push_back(new Canvas(color, base)); return ExistingCanvas.size(); }
		static void Update() {}
		static void Shutdown() 
		{
			for (auto canvas : ExistingCanvas) 
			{
				if (canvas)
				{
					canvas->Close();
					delete canvas;
					canvas = nullptr;
				}
			}
			ExistingCanvas.clear();
		}
		static int ActiveCanvas;
	};
}

