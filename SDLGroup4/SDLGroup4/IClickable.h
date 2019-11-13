#pragma once
#include "GameElement.h"
#include <functional>

struct SDL_Color;

namespace Engine {
	class IClickable : public GameElement
	{
	public:
		std::function<void()> OnClick;
		virtual void OnHover() = 0;
		virtual void LeavingHover() = 0;
		SDL_Color* HoverForegroundColor = nullptr;
		SDL_Color* ForegroundColor = nullptr;

		int MouseCurrentStatus;
		
		
	};		
	enum MouseStatus
	{
		None = 1,
		Hover = 2
	};
	
}





