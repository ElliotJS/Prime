#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "utility/StateMachine.h"
#include "utility/AssetManager.h"

namespace Prime {
	struct GameData {
		StateMachine machine;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game {
	public :
		Game(int width, int height, std::string title);

	private:
		GameDataRef _data = std::make_shared<GameData>();

		const float dt = 1.0f / 120.0f;
		sf::Clock _clock;

		void Run();
	};
}