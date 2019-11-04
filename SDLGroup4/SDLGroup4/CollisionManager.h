#pragma once
#include <vector>

namespace Engine {
	class Collider;
	class CollisionManager
	{
	public:
		static void AddNewCollider(Engine::Collider* col);
		static void Update();
		static void Shutdown();
	private:
		static std::vector<Collider*> colliders;
	};
}

