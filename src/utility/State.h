#pragma once

#include <SFML/Graphics.hpp>
#include "../rendering/Camera.h"
#include "InputManager.h"
#include "../DEFINITIONS.h"
#include "../KEYS.h"

namespace Prime {
	class State {
	public :
		virtual void Init() = 0;

		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw() = 0; 
		
		virtual void Pause() {}
		virtual void Resume() {}
	protected:
		sf::Sprite _background;
	};
}