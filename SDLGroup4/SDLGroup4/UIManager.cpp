#include "UIManager.h"
namespace Engine
{
	std::vector<Canvas*> UIManager::Scenes;
	int UIManager::ActiveScene;
	void UIManager::Initialize()
	{
		ActiveScene = 0;
		CreateScene({ 0, 0, 0, 255 }, { 900, 600, 250, 150 });
	}
	void UIManager::Initialize(SDL_Color color, GameElement base)
	{
		ActiveScene = 0;
		CreateScene(color, base);
	}
	void UIManager::AddObjectsToScene(int scene, std::vector<GameElement*> childObject)
	{
		for (int i = 0; i < childObject.size(); i++)
		{
			Scenes[scene]->AddChild(childObject[i]);
		}
	}
}