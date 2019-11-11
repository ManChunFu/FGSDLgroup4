#include "Button.h"
#include "Window.h"
#include "Canvas.h"
#include <SDL_events.h>
#include <SDL_pixels.h>
#include <SDL_render.h>



Engine::Button::Button(GameElement base, SDL_Color color)
{
	boxRect.w = width = base.width;
	boxRect.h = height = base.height;
	boxRect.x = xCoordinate = base.xCoordinate;
	boxRect.y = yCoordinate = base.yCoordinate;

	this->color = color;
}

void Engine::Button::AddChild(GameElement* element, void(*function))
{
	Children.push_back(element);
}

void Engine::Button::UpdatePosition(float xCoordinate, float yCoordinate)
{
	boxRect.x = this->xCoordinate = xCoordinate;
	boxRect.y = this->yCoordinate = yCoordinate;
}

void *Engine::Button::OnClickEventPlay()
{
	SDL_Event event;
	if(SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_MOUSEBUTTONDOWN || event.key.keysym.sym == SDLK_EXECUTE)
		{
			Children.clear();
			Engine::Canvas* tempCanvas = new Engine::Canvas();
			tempCanvas->Close();
		}
	}
	return NULL;
}

void Engine::Button::Render()
{
	SDL_SetRenderDrawColor(Engine::Window::Renderer, color.r, color.g, color.g, color.a);
	SDL_RenderDrawRect(Engine::Window::Renderer, &boxRect);

	for (int8_t index = 0; index < Children.size(); index++)
		Children[index]->Render();
}


