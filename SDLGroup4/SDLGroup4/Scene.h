#pragma once
#include "UIManager.h"
#include "Text.h"
#include "Button.h"
namespace Engine 
{
	class CollisionManager;
	class Scene
	{
	public:
		Scene();
		void Shutdown();
	private:
		CollisionManager* colManager;
	};
}

