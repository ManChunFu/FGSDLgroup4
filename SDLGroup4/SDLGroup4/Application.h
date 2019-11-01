#pragma once
#include "Window.h"

namespace Engine
{
	class Application 
	{
	public:
		~Application() {};
		
		
		bool Initialize();
		void Run();
		void Shutdown();


	private:
		bool isRunning;
		Engine::Window* window = nullptr;
	};
}
