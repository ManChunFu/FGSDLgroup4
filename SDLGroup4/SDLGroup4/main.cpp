#include "Application.h"
#include "TextureManager.h"
#include "Window.h"


int main(int argc, char** argv)
{
	Engine::Application* application = new Engine::Application();
	
	if (!application->Initialize())
	{
		application->Shutdown();
		delete application;
		application = nullptr;
	}
	

	application->Run();
	application->Shutdown();
	delete application;
	application = nullptr;

	return 0;
}