#include "Canvas.h"
#include "Window.h"
#include <SDL_pixels.h>
#include <SDL_render.h>

void Engine::Canvas::AddChild(GameElement * element)
{	
	Children.push_back(element);
}

void Engine::Canvas::Render()
{
	SDL_Rect rect = { xCoordinate, yCoordinate,width, height };
		
	SDL_RenderClear(Engine::Window::Renderer);
	SDL_SetRenderDrawColor(Engine::Window::Renderer, Color.r, Color.g, Color.b, Color.a);
	SDL_RenderFillRect(Engine::Window::Renderer, &rect);

	for (int8_t index = 0; index < Children.size(); index++)
		Children[index]->Render();
}
