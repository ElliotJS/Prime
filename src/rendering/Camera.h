#pragma once

#include "SFML/Graphics.hpp"

namespace Display {
	namespace Camera {
		sf::Sprite ScaleSprite(sf::Sprite sprite);
		void Draw(const sf::Drawable& drawable);
		void DrawSprite(sf::Sprite sprite);
	}
}