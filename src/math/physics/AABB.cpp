#include "AABB.h"
#include <SFML/Graphics.hpp>
#include "../../rendering/Camera.h" 

namespace Prime {
	namespace Physics {
		AABB::AABB() {
			id = std::rand();
			this->layer = DEFAULT;
		}

		AABB::AABB(Layers layer, int id)
		{
			id = std::rand();
			parentID = id;
			this->layer = layer;
		}
		
		bool AABB::operator==(const AABB& rhs)
		{
			return (id == rhs.id);
		}

		void AABB::Draw() {
			sf::RectangleShape rect(sf::Vector2f(max.x - min.x, max.y - min.y));
			rect.setPosition(min.x, min.y);
			rect.setSize(sf::Vector2f(max.x - min.x, max.y - min.y));

			rect.setFillColor(sf::Color::Magenta);

			Display::Camera::Draw(rect);
		}
	}
}