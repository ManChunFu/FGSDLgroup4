#pragma once
#include "Window.h"
#include "Canvas.h"
#include <vector>
namespace Engine
{
	class Window;
	class InputManager;
	class Entity;
	class Scene;
	class Application 
	{
	public:
		~Application() {};
		void Quit() { isRunning = false; }
		
		bool Initialize();
		void Run();
		void Shutdown();
		Engine::Window* window = nullptr;
		Engine::InputManager* inputManager = nullptr;
		void LoadScene(int scene);
		bool Pause = false;
	private:
		std::vector<Scene*> scenes;
		void Update();
		void HandleEvents();
		void Render();
		bool isRunning = true;


	};

	Application* CreateApplication();
}
