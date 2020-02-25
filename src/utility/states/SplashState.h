#pragma once

#include "SFML/Graphics.hpp"
#include "../State.h"
#include "../../Game.h"

namespace Prime {
	class SplashState : public State {
		public:
			SplashState(GameDataRef data);

			void Init();

			void HandleInput();
			void Update(float dt);
			void Draw();

		private:
			GameDataRef _data;

			sf::Clock _clock;
	};
}