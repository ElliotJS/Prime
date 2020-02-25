#pragma once

#include "../Vector2.h"

namespace Prime {
	namespace Physics {
		enum Layers { 
			DEFAULT,
			PLAYER,
			SOLID,
			PICKUP
		};

		class AABB {
		public:
			AABB();
			AABB(Layers layer, int id);

			int parentID;

			Layers layer;

			Vector2<float> min;
			Vector2<float> max;

			int id;

			void Draw();

			bool operator== (const AABB& rhs);
		};
	}
}