#pragma once
#include <vector>
namespace Engine {
	class Entity;
	class EntityManager
	{
	public:
		static void Update();
		static void Render();
		static void AddEntity(Entity* add);
		static void Shutdown();
	private:
		static std::vector<Entity*> entities;
	};
}

