#pragma once

#include <memory>

namespace Prime {
	class WorldObject
	{
	public:
		int id = 0;

		virtual void Update(float dt) = 0;
		void Draw();
	};

	typedef std::unique_ptr<WorldObject> WorldObjectRef;
}