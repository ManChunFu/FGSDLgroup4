#pragma once

#include "GameElement.h"
#include <string>
#include <vector>

#include <SDL_events.h>
#include <functional>
#include "IClickable.h"

struct SDL_Rect;
struct SDL_Color;

namespace Engine
{
	class Button: public GameElement
	{
	public:
		Button(GameElement base, SDL_Color color);
		
		void SetText(GameElement* element);
		void SetOnClickEvent(std::function<void()> function);
		void UpdatePosition(float xCoordinate, float yCoordinate) override;
		std::function<void()> OnClick;
		void Render() override;		
		
		GameElement* TextElement;

	private:
		SDL_Rect boxRect;
		SDL_Color color;
		

		// Inherited via IClickable

	};
}

