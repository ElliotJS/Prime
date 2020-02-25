#pragma once

#include <list>
#include "AABB.h"

namespace Prime {
	namespace Physics {
		void AddAABB(AABB a);

		std::list<AABB> GetAABBs();
		std::list<AABB> GetAABBs(Layers layer);

		bool AABBvAABB(AABB a, AABB b);
	}
}