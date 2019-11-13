#pragma once
#include "Window.h"
#include "Canvas.h"

namespace Engine
{
	class Window;
	class InputManager;
	class Entity;
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

	private:
		void Update();
		void HandleEvents();
		void Render();
		bool isRunning = true;


	};

	Application* CreateApplication();
}
