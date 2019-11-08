#pragma once

#include <Application.h>

class Game : public Engine::Application
{

};

Engine::Application* Engine::CreateApplication()
{
	return new Game();
}

