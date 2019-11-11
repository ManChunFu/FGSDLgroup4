#pragma once

#include "GameElement.h"
#include <string>
#include <vector>
#include <SDL_events.h>

struct SDL_Rect;
struct SDL_Color;

namespace Engine
{
	class Button: public GameElement
	{
	public:
		Button(GameElement base, SDL_Color color);
		
		void AddChild(GameElement* element, void (*function));
		void UpdatePosition(float xCoordinate, float yCoordinate) override;
		void *OnClickEventPlay();
		void Render() override;

		 
		std::string text;
		std::vector<GameElement*> Children;


	private:
		SDL_Rect boxRect;
		SDL_Color color;
		
	};
}

