#pragma once

#include "Vector2D.h"
#include "TextureManager.h"
#include <string>
#include <vector>


namespace Engine
{
	class Animation
	{
	public:
		Animation(const std::string& _spritePath, const std::string& _name, int _spriteSheetLenghtX, int _spriteSheetLengthY, int _speed, bool _runFullClip);
		~Animation() {}
		void PlayAnimation(Vector2D& position, SDL_RendererFlip flip);
		std::string name = "";
		bool stopPlaying = false; 
		bool runFullClip = false;
		void ChangeScale(float amount);
		void ChangeScale(float x, float y);
	private:
		std::string spritePath = "";
		int spriteSheetLengthX = 0, spriteSheetLengthY = 0;
		int speed = 0;
		int spriteWidth = 0, spriteHeight = 0;
		int frameWidth = 0, frameHeight = 0;
		SDL_Rect sourceRect, destinationRect;
		SDL_Texture* newAnimation;
		const int framePerSecond = 60;
		int framtime = 0;
	};
}

