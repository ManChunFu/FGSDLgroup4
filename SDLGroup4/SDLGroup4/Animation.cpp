//#include "Animation.h"
//
//#include <iostream>
//#include "Vector2D.h"
//
//
//
//namespace Engine {
//
//	Animation::Animation(const std::string _spritePath, std::string name, int _totalSpritesInRow, int _totalSpritesInColumn, int desPositionX, int desPositionY)
//	{
//	}
//
//	Animation::~Animation()
//	{
//	}
//
//	void Animation::AnimationSetup(const std::string _spritePath, int totalSpritesInOneRow, int totalSpritesInOneColumn, Vector2D desPosition)
//	{
//		SDL_Texture* newAnimation;
//		newAnimation = Engine::TextureManager::Texture(_spritePath);
//		if (newAnimation == nullptr)
//			std::cout << "Failed to load sprite. SDL Error: " << SDL_GetError << std::endl;
//		else
//		{
//			spritePath = _spritePath;
//
//			SDL_QueryTexture(newAnimation, nullptr, nullptr, &textureWidth, &textureHeight);
//
//			frameWidth = textureWidth / totalSpritesInOneRow;
//			frameHeight = textureHeight / totalSpritesInOneColumn;
//			src.x = src.y = 0;
//			src.w = frameWidth;
//			src.h = frameHeight;
//			des.x = desPosition.X;
//			des.y = desPosition.Y;
//			des.w = frameWidth;
//			des.h = frameHeight;
//		}
//
//		if (&src == nullptr || &des == nullptr)
//			std::cout << "Failed to setup animated sprite's source / destination value. SDL Error: " << SDL_GetError << std::endl;
//	}
//
//	void Animation::PlayAnimation(int speed)
//	{
//		framtime++;
//
//		if (framePerSecond / framtime == speed)
//		{
//			framtime = 0;
//			src.x += frameWidth;
//			if (src.x >= textureWidth)
//				src.x = 0;
//		}
//
//
//		Engine::TextureManager::Draw(Engine::TextureManager::Texture(spritePath), src, des);
//
//	}
//}
