#pragma once

#include <vector>
#include "WorldObject.h"

namespace Prime {
	class Scene
	{
	public:
		Scene();
		
		void Update(float dt);
		void Draw();

		void RemoveID(int id);
		WorldObjectRef GetObject(int id);

	private:

		std::vector<int> _objectsToBeDeleted;
		std::vector<WorldObjectRef> _worldObjects;

		void DeleteObject(int id);
		void DeleteAll();

		int _playerID;

	};
}