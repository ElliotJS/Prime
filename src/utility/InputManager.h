#pragma once

#include <SFML/Graphics.hpp>
#include <list>

namespace Prime {
    class InputManager {
        public:
            bool IsKeyPressed(sf::Keyboard::Key keycode); // Returns true if the key is pressed.
            bool IsKeyDown(sf::Keyboard::Key keycode); // Returns true if the key was just pressed.
            bool IsKeyUp(sf::Keyboard::Key keycode); // Returns true if the key was just released.

            bool IsMouseOver(sf::RectangleShape rect);

            void Setup();
            void Update();
        private:
            bool _currentKeyState[sf::Keyboard::KeyCount];
            bool _previousKeyState[sf::Keyboard::KeyCount];
    };
}