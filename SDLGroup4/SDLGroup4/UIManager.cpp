#include "UIManager.h"
namespace Engine
{
	std::vector<Canvas*> UIManager::ExistingCanvas;
	int UIManager::ActiveCanvas;
	void UIManager::Initialize()
	{
		ActiveCanvas = 0;
		CreateScene({ 0, 0, 0, 255 }, { 900, 600, 250, 150 });
	}
	void UIManager::Initialize(SDL_Color color, GameElement base)
	{
		ActiveCanvas = 0;
		CreateScene(color, base);
	}
	void UIManager::AddObjectsToScene(int scene, std::vector<GameElement*> childObject)
	{
		for (int i = 0; i < childObject.size(); i++)
		{ ExistingCanvas[scene]->AddChild(childObject[i]); }
	}
}