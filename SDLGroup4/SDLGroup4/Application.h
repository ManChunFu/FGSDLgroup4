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
		
		
		bool Initialize();
		void Run();
		void Shutdown();


	private:
		void Update();
		void HandleEvents();
		void Render();
		bool isRunning = true;
		Engine::Window* window = nullptr;
		Engine::InputManager* inputManager = nullptr;
		Engine::Entity* entity;

	};

	Application* CreateApplication();
}
