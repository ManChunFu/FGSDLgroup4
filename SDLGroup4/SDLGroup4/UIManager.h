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
		static void AddObjectsToCanvas(int scene, std::vector<GameElement*> childObjects);
		static void Render() { 
			if (ExistingCanvas.size() > 0 && ActiveCanvas < ExistingCanvas.size()) ExistingCanvas[ActiveCanvas]->Render(); 
		}
#pragma warning( push )
#pragma warning( disable : 4267)
		static int CreateCanvas(SDL_Color color, GameElement base) { ExistingCanvas.push_back(new Canvas(color, base)); return ExistingCanvas.size(); }
		static int CreateCanvas(SDL_Color color) { ExistingCanvas.push_back(new Canvas(color, { 900, 600, 250, 150 })); return ExistingCanvas.size(); }
		static int CreateCanvas() { ExistingCanvas.push_back(new Canvas({ 0,0,0,255 }, { 1440,900,0,0 })); return ExistingCanvas.size(); }
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

		static void CleanElement(int scene);
	};
#pragma warning( pop ) 
}

