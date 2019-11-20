#include "Button.h"
#include "Window.h"
#include "Canvas.h"
#include <SDL_events.h>
#include <SDL_pixels.h>
#include <SDL_render.h>
#include "SoundManager.h"

Engine::Button::Button(GameElement base, SDL_Color color)
{
	boxRect.w = width = base.width;
	boxRect.h = height = base.height;
	boxRect.x = xCoordinate = base.xCoordinate;
	boxRect.y = yCoordinate = base.yCoordinate;

	this->color = color;
}

void Engine::Button::SetText(Text* element)
{
	element->UpdatePosition(element->xCoordinate + this->xCoordinate, element->yCoordinate + this->yCoordinate);
	delete TextElement;
	TextElement = element;
}

void Engine::Button::SetOnClickEvent(std::function<void()> function)
{
	this->OnClick = function;
}

void Engine::Button::UpdatePosition(float xCoordinate, float yCoordinate)
{
	boxRect.x = this->xCoordinate = xCoordinate;
	boxRect.y = this->yCoordinate = yCoordinate;
}


void Engine::Button::Render()
{
	SDL_SetRenderDrawColor(Engine::Window::Renderer, color.r, color.g, color.g, color.a);
	SDL_RenderDrawRect(Engine::Window::Renderer, &boxRect);

	TextElement->Render();
}

void Engine::Button::OnHover()
{
	TextElement->ChangeTextColor(HoverForegroundColor);
	SoundManager::PlaySoundEffect("Button", 0, 100);
}

void Engine::Button::LeavingHover()
{
	TextElement->ChangeTextColor(ForegroundColor);
}



