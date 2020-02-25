#pragma once

#include "SFML/Graphics.hpp"

#include "../Game.h"
#include "../rendering/Renderable.h"
#include "Button.h"

namespace Prime {
	class Menu : public Renderable {
	public:
		Menu(GameDataRef data);
		void MoveUp();
		void MoveDown();

		void HandleInput();
		void Update(float dt);
		void Draw();

		std::vector<Button> _buttons;

	private:
		void UpdateSelected();

		GameDataRef _data;

		int current = 0;
	};
}