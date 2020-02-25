#include "Camera.h"
#include "../DEFINITIONS.h"
#include "../Debug.h"
#include "Display.h"
#include "../math/Vector2.h"

namespace Display {
	namespace Camera {
		namespace {
			Vector2<float> loc;
		}

		sf::Sprite ScaleSprite(sf::Sprite sprite) {
			/*
			sprite.setScale(SCREEN_SCALE_X, SCREEN_SCALE_X);
			*/
			sprite.setPosition((ADJUSTED_WIDTH - sprite.getGlobalBounds().width) / 2, (ADJUSTED_HEIGHT - sprite.getGlobalBounds().height) / 2);
			
			return sprite;
		}

		void Draw(const sf::Drawable& drawable) {
			Display::draw(drawable);
		}

		void DrawSprite(sf::Sprite sprite) {
			/*
			Vector2<float> loc(sprite.GetSprite().getPosition().x, sprite.GetSprite().getPosition().y);
			Vector2<float> center(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
			Vector2<float> diff = loc - center;
			sf::Sprite printSprite = sprite.GetSprite();
			printSprite.setPosition(sf::Vector2f(diff.x * SCREEN_SCALE_X, diff.y * SCREEN_SCALE_X));
			printSprite.setScale(sprite.GetSprite().getScale());
			*/
			Draw(sprite);
		}
	}
}