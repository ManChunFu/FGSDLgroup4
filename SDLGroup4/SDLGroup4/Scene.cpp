#include "Scene.h"
#include "CollisionManager.h"
namespace Engine {
	Scene::Scene()
	{
		colManager = new CollisionManager();
	}
	void Scene::Shutdown()
	{
		if (colManager) delete colManager;
		colManager = nullptr;
	}
}
