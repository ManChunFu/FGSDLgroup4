#include "Application.h"
#include "TextureManager.h"
#include "Window.h"


int main(int argc, char** argv)
{
	Engine::Application* application = new Engine::Application();
	Engine::TextureManager* texture(,80, 80, 120, 120, "Assets/Sprites/enemy_drone_larger_red");
	
	if (!application->Initialize()) {
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