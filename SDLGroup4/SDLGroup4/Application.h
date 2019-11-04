#pragma once
#include "Window.h"

namespace Engine
{
	class InputManager;
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
		
	};
}
