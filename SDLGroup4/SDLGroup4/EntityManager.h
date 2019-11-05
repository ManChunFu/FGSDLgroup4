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
	private:
		static std::vector<Entity*> entities;
	};
}

