#pragma once
#include <SDL_rect.h>
#include <string>
#include "CollisionManager.h"
namespace Engine {
	class Collider {
	public:
		Collider(SDL_Rect destRect) : topBorder(destRect.y - (destRect.h * 0.5f)), bottomBorder(destRect.y + (destRect.h * 0.5f)), 
			leftBorder(destRect.x - (destRect.w * 0.5f)), rightBorder(destRect.x + (destRect.w * 0.5f))
		{
			Engine::CollisionManager::AddNewCollider(this);
		};
		int TopBorder() { return topBorder; }
		int BottomBorder() { return bottomBorder; }
		int LeftBorder() { return leftBorder; }
		int RightBorder() { return rightBorder; }
		Collider* collisionTarget = nullptr;
		std::string tag = "";
	private:
		int topBorder = 0, bottomBorder = 0, leftBorder = 0, rightBorder = 0;

	};
}