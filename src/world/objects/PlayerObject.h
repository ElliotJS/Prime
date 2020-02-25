#pragma once

#include "../WorldObject.h"

namespace Prime {
	class PlayerObject : public WorldObject
	{
	public:
		void Update(float dt);
	};
}