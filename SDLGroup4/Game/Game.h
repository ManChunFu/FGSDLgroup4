#pragma once

#include <Application.h>
#include <Canvas.h>
#include <Text.h>
#include <Image.h>


class Game : public Engine::Application
{
public:

		
};

Engine::Application* Engine::CreateApplication()
{
	return new Game();
}

