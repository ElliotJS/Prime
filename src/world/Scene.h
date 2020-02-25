#pragma once

#include "../utility/states/PlayState.h"
#include "WorldObject.h"

namespace Prime {
	class Scene
	{
	public:
		Scene();
		
		void Update(float dt);
		void Draw();

		void RemoveID(int id);
		WorldObject GetObject(int id);

	private:

		std::vector<int> _objectsToBeDeleted;
		std::vector<WorldObject	> _worldObjects;

		void DeleteObject(int id);
		void DeleteAll();

		int _playerID;

	};
}