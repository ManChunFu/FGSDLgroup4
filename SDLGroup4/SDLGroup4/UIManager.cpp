#include "UIManager.h"
namespace Engine
{
	std::vector<Canvas*> UIManager::ExistingCanvas;
	int UIManager::ActiveCanvas;
	void UIManager::Initialize()
	{
		ActiveCanvas = 0;
		CreateCanvas();
	}
	void UIManager::Initialize(SDL_Color color, GameElement base)
	{
		ActiveCanvas = 0;
		CreateCanvas(color, base);
	}
	void UIManager::AddObjectsToCanvas(int scene, std::vector<GameElement*> childObject)
	{
		for (int i = 0; i < childObject.size(); i++)
		{ ExistingCanvas[scene]->AddChild(childObject[i]); }
	}
}