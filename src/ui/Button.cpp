#include "Button.h"
#include "../rendering/Display.h"
#include "../Game.h"
#include "../DEFINITIONS.h"
#include <iostream>

namespace Prime {
	Button::Button(GameDataRef data, std::string text, float x, float y, std::function<void()> perform) : _data(data) {
		action = perform;

		_data->assets.LoadFont("Charnego", MAIN_FONT);

		_text.setString(text);
		_text.setFillColor(sf::Color::White);
		_text.setFont(_data->assets.GetFont("Charnego"));
		_text.setCharacterSize(120);
		_text.setPosition(x - _text.getGlobalBounds().width / 2, y - _text.getGlobalBounds().height / 2);
	}

	sf::Text Button::GetText() {
		return _text;
	}

	sf::RectangleShape Button::GetBounds() {
		sf::RectangleShape rect;
		rect.setPosition(_text.getPosition());
		rect.setSize(sf::Vector2f(_text.getGlobalBounds().width, _text.getGlobalBounds().height));
		return rect;
	}

	void Button::Draw() {
		if (selected)
			_text.setFillColor(sf::Color::Cyan);
		else
			_text.setFillColor(sf::Color::Blue);
		 
		Display::draw(_text);
	}
}