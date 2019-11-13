#pragma once
#include <SDL_rect.h>
#include <SDL_Image.h>
#include <string>
#include <vector>
#include "CollisionManager.h"
#include <iostream>
namespace Engine {
	class Collider {
	public:
		Collider(SDL_Rect destRect, std::string colliderTag) : topBorder(destRect.y - (int)(destRect.h * 0.5f)), bottomBorder(destRect.y + (int)(destRect.h * 0.5f)),
			leftBorder(destRect.x - (int)(destRect.w * 0.5f)), rightBorder(destRect.x + (int)(destRect.w * 0.5f))
		{
			
			tag = colliderTag;
		};
		void UpdateBorders(SDL_Rect destRect)
		{
			topBorder = destRect.y;
			bottomBorder = destRect.y + destRect.h;
			leftBorder = destRect.x;
			rightBorder = destRect.x + destRect.w;
			width = destRect.w;
			height = destRect.h;
		};
		int TopBorder() { return topBorder; }
		int BottomBorder() { return bottomBorder; }
		int LeftBorder() { return leftBorder; }
		int RightBorder() { return rightBorder; }
		int Width() { return width; }
		int Height() { return height; }
		bool HasSurface(){
			if (surface) return true;
			return false;
		}
		std::vector<Collider*> collisions;
		std::string tag = "";
	private:
		int topBorder = 0, bottomBorder = 0, leftBorder = 0, rightBorder = 0, width = 0, height = 0;
		SDL_Surface* surface;
		float scale = 0;

	};
}