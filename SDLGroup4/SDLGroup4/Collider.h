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
		Collider(SDL_Rect destRect, std::string colliderTag, SDL_Surface* pointer) : topBorder(destRect.y - (int)(destRect.h * 0.5f)), bottomBorder(destRect.y + (int)(destRect.h * 0.5f)),
			leftBorder(destRect.x - (int)(destRect.w * 0.5f)), rightBorder(destRect.x + (int)(destRect.w * 0.5f))
		{
			Engine::CollisionManager::AddNewCollider(this);
			tag = colliderTag;
			surface = pointer;
			width = destRect.w;
			height = destRect.h;
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
		bool CheckAreaForAlpha(int startX, int startY, int width, int height) {
			int bpp;
			Uint8* p;
			Uint32 pixelColor;
			for (int i = 0; i < width; i++)
			{
				for (int a = 0; a < height; a++)
				{
					bpp = surface->format->BytesPerPixel;
					p = (Uint8*)surface->pixels + startY * surface->pitch + startX * bpp;
					switch (bpp)
					{
					case(1):
						pixelColor = *p;
						break;
					case(2):
						pixelColor = *(Uint16*)p;
						break;
					case(3):
						if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
							pixelColor = p[0] << 16 | p[1] << 8 | p[2];
						else
							pixelColor = p[0] | p[1] << 8 | p[2] << 16;
						break;
					case(4):
						pixelColor = *(Uint32*)p;
						break;
					}
					Uint8 red, green, blue, alpha;
					SDL_GetRGBA(pixelColor, surface->format, &red, &green, &blue, &alpha);
					//std::cout << (int)alpha;
					if (alpha > 100) return true;
					startY++;
				}
				startX++;
			}
			return false;
			
		}
	private:
		int topBorder = 0, bottomBorder = 0, leftBorder = 0, rightBorder = 0, width = 0, height = 0;
		SDL_Surface* surface;

	};
}