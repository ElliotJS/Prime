#pragma once

#include <functional>
#include "SFML/Graphics.hpp"
#include "../DEFINITIONS.h"
#include "../Game.h"
#include "../rendering/Renderable.h"

namespace Prime {
	class Button : public Renderable
	{
	public:
		Button(GameDataRef data, std::string text, float x, float y, std::function<void()> perform);
		void Draw();
		
		sf::Text GetText();
		sf::RectangleShape GetBounds();

		std::function<void()> action;
		bool selected = false;
	private:
		GameDataRef _data;

		sf::Text _text;
	};
}
