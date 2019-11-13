#pragma once
#include <vector>

namespace Engine {
	class Collider;
	class CollisionManager
	{
	public:
		void AddNewCollider(Engine::Collider* col);
		void Update();
		void Shutdown();
	private:
	  std::vector<Collider*> colliders;
	};
}

