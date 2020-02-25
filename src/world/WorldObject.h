#pragma once

namespace Prime {
	class WorldObject
	{
	public:
		int id;

		void Update(float dt);
		void Draw();
	};
}