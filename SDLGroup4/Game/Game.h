#pragma once

#include <Application.h>
#include <Canvas.h>
#include <Text.h>
#include <Image.h>
#include <Button.h>

namespace Engine
{
	class Button;
}

class Game : public Engine::Application
{
public:
	
		
};

Engine::Application* Engine::CreateApplication()
{
	return new Game();
}

void OnClickMyButton();
Engine::Button* PlayButton;