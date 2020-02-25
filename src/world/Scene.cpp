#include "Scene.h"

#include "objects/PlayerObject.h"

namespace Prime {
	Scene::Scene()
	{
		_worldObjects.push_back(WorldObjectRef(new PlayerObject()));
	}

	void Scene::Update(float dt)
	{
		for (WorldObjectRef& wO : _worldObjects) {
			wO.get()->Update(dt);
		}
		DeleteAll();
	}

	void Scene::Draw()
	{
		for (WorldObjectRef& wO : _worldObjects) {
			wO.get()->Draw();
		}
	}

	void Scene::DeleteObject(int id)
	{
		int cnt = 0;
		for (WorldObjectRef& wO : _worldObjects) {
			if (wO.get()->id == id) {
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

	WorldObjectRef Scene::GetObject(int id)
	{
		for (WorldObjectRef& wO : _worldObjects) {
			if (wO.get()->id == id) {				
				return WorldObjectRef(wO.get());
			}
		}
	}
}