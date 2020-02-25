#include "Scene.h"

namespace Prime {
	Scene::Scene()
	{
	}

	void Scene::Update(float dt)
	{
		for (WorldObject& wO : _worldObjects) {
			wO.Update(dt);
		}
		DeleteAll();
	}

	void Scene::Draw()
	{
		for (WorldObject& wO : _worldObjects) {
			wO.Draw();
		}
	}

	void Scene::DeleteObject(int id)
	{
		int cnt;
		for (WorldObject& wO : _worldObjects) {
			if (wO.id == id) {
				_worldObjects.erase(_worldObjects.begin() + cnt);
				return;
			}
			cnt++;
		}
	}

	void Scene::DeleteAll()
	{
		for (int i : _objectsToBeDeleted) {
			DeleteObject(i);
		}
		_objectsToBeDeleted.clear();
	}

	void Scene::RemoveID(int id)
	{
		_objectsToBeDeleted.push_back(id);
	}

	WorldObject Scene::GetObject(int id)
	{
		return WorldObject();
	}
}