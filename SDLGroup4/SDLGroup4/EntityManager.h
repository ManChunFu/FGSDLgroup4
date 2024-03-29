#pragma once
#include <vector>
namespace Engine {
	class Entity;
	class EntityManager
	{
	public:
		void Update();
		void Render();
		void RemoveEntity(Entity* ent);
		void AddEntity(Entity* add);
		void Shutdown();
	private:
		std::vector<Entity*> entities;
	};
}

