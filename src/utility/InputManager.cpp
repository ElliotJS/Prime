#include "InputManager.h"
#include "../rendering/Display.h"
#include <list>

namespace Prime {
	void InputManager::Setup() {
		memset(_currentKeyState, false, sizeof(_currentKeyState));
		memset(_previousKeyState, false, sizeof(_previousKeyState));
	}

	void InputManager::Update() {
		for (unsigned int i = 0; i < sf::Keyboard::KeyCount; ++i)
		{
			_previousKeyState[i] = _currentKeyState[i];

			_currentKeyState[i] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i);
		}
	}

	bool InputManager::IsKeyDown(sf::Keyboard::Key keycode) {
		//return false;
		return (_currentKeyState[keycode] && Display::isFocused());
	}

	bool InputManager::IsKeyPressed(sf::Keyboard::Key keycode) {
		//return false;
		return (_currentKeyState[keycode] && !_previousKeyState[keycode] && Display::isFocused());
	}

	bool InputManager::IsMouseOver(sf::RectangleShape rect) {
		sf::Vector2i mousePos = sf::Vector2i(sf::Mouse::getPosition().x / SCREEN_SCALE_X, sf::Mouse::getPosition().y / SCREEN_SCALE_X);
		if (mousePos.x > rect.getPosition().y && mousePos.x < rect.getPosition().x + rect.getGlobalBounds().width &&
			mousePos.y > rect.getPosition().y && mousePos.y < rect.getPosition().y + rect.getGlobalBounds().height) {
			return true;
		}
		return false;
	}

	bool InputManager::IsKeyUp(sf::Keyboard::Key keycode) {
		//return false;
		return (!_currentKeyState[keycode] && _previousKeyState[keycode] && Display::isFocused());
	}
}
