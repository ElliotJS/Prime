#pragma once

#include "SFML/Graphics.hpp"
#include "../State.h"
#include "../../Game.h"  
#include "../../world/Scene.h"

namespace Prime {

	class PlayState : public State {
	public:
		PlayState();
		PlayState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw();
	private:
		GameDataRef _data;

		Scene _scene;
	};
}