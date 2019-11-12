#pragma once

#include <Application.h>
#include <Canvas.h>
#include <Text.h>
#include <Image.h>


class Game : public Engine::Application
{
public:
private:
		
};

Engine::Application* Engine::CreateApplication()
{
	return new Game();
}

Engine::Application* application;
void OnClickQuitButton();
void OnClickPlayButton();
void OnClickScoreButton();

Engine::Text* startMenuTitle;
Engine::Button* playButton;
Engine::Text* playText;
Engine::Button* quitButton;
Engine::Text* quitText;
Engine::Button* scoreButton;
Engine::Text* scoreRecordText;
