#include "Physics.h"
#include "../../Debug.h"

namespace Prime {
	namespace Physics {
		namespace {
			std::list<AABB> aabbs;
		}

		void AddAABB(AABB a) {
			aabbs.push_back(a);
		}

		std::list<AABB> GetAABBs() {
			return aabbs;
		}

		std::list<AABB> GetAABBs(Layers layer)
		{
			std::list<AABB> layerList;
			for (auto& aabb : aabbs) {
				if (aabb.layer == layer) {
					layerList.push_back(aabb);
				}
			}
			return layerList;
		}

		bool AABBvAABB(AABB a, AABB b) {
			if (a == b) {
				return false;
			}
			if (a.max.x < b.min.x or a.min.x > b.max.x)
				return false;
			if (a.max.y < b.min.y or a.min.y > b.max.y)
				return false;

			//Debug::log(std::to_string(a.min.x) + " " + std::to_string(a.max.x) + " " + std::to_string(b.min.x) + " " + std::to_string(b.max.x));
			//Debug::log(std::to_string(a.min.y) + " " + std::to_string(a.max.y) + " " + std::to_string(b.min.y) + " " + std::to_string(b.max.y));

			return true;
		}
	}
}