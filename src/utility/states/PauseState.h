#pragma once

#include "SFML/Graphics.hpp"
#include "../State.h"
#include "../../Game.h"
#include "../../UI/Menu.h"

namespace Prime {
	class PauseState : public State {
	public:
		PauseState(GameDataRef data);

		void Init();
		
		void HandleInput();
		void Update(float dt);
		void Draw();

		void Play();
		void Options();
		void Exit();

	private:
		GameDataRef _data;

		Menu _menu;
	};
}