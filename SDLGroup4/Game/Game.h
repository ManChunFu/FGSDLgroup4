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

void OnClickMyButton();
Engine::Text* startMenuTitle;
Engine::Button* playButton;
Engine::Text* playText;
Engine::Button* quitButton;
Engine::Text* quitText;
Engine::Button* scoreButton;
Engine::Text* scoreRecordText;
