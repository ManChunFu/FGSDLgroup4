#pragma once

#include "IClickable.h"
#include <string>
#include <vector>

#include <SDL_events.h>

struct SDL_Rect;
struct SDL_Color;

namespace Engine
{
	class Button: public IClickable
	{
	public:
		Button(GameElement base, SDL_Color color);
		
		void SetText(GameElement* element);
		void SetOnClickEvent(std::function<void()> function);
		void UpdatePosition(float xCoordinate, float yCoordinate) override;
		void Render() override;		
		
		GameElement* TextElement;

	private:
		SDL_Rect boxRect;
		SDL_Color color;
		

		// Inherited via IClickable


		// Inherited via IClickable

	};
}

