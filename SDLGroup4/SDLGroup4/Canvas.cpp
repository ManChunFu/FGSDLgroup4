#include "Canvas.h"
#include "Window.h"
#include <SDL_pixels.h>
#include <SDL_render.h>

void Engine::Canvas::AddChild(GameElement * element)
{	
	element->UpdatePosition(element->xCoordinate + this->xCoordinate, element->yCoordinate + this->yCoordinate);
	Children.push_back(element);
}

void Engine::Canvas::Render()
{
	SDL_Rect rect = { xCoordinate, yCoordinate,width, height };
		
	SDL_SetRenderDrawColor(Engine::Window::Renderer, Color.r, Color.g, Color.b, Color.a);
	SDL_RenderFillRect(Engine::Window::Renderer, &rect);


	for (int8_t index = 0; index < Children.size(); index++)
		Children[index]->Render();
}

void Engine::Canvas::UpdatePosition(float xCoordinate, float yCoordinate)
{
}
