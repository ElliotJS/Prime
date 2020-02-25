#include "Game.h"
#include "utility/states/SplashState.h"
#include "rendering/Display.h"
#include "Debug.h"
#include <iostream>
#include "KEYS.h"

namespace Prime {
	Game::Game(int width, int height, std::string title) {
		_data->input.Setup();

		Display::init("Window");

		_data->machine.AddState(StateRef(new SplashState(_data)));

		_data->assets.LoadFont("Arial", DEBUG_FONT);
		Debug::init(_data->assets.GetFont("Arial"));

		this->Run();
	}

	void Game::Run() {
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		int lastFrameTime = 0;
		int frames = 0;

		while (Display::isOpen()) {
			_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f) {
				frameTime = 0.25f;
			}

			if (newTime - lastFrameTime > 1) {
				lastFrameTime = (int)newTime;
				//std::cout << frames << std::endl;
				std::string log = "FPS: ";
				log += std::to_string(frames);
				Debug::log(log);
				frames = 0;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt) {
				_data->input.Update();
				_data->machine.GetActiveState()->HandleInput();
				_data->machine.GetActiveState()->Update(dt);

				frames += 1;

				accumulator -= dt;
			}

			if (_data->input.IsKeyPressed(KEY_TOGGLE_DEBUG)) {
				if (Debug::isOpen()) {
					Debug::close();
				}
				else {
					Debug::show();
				}
			}

			interpolation = accumulator / dt;

			Display::setPos();
			Display::clear({ 0, 0, 0 });
			_data->machine.GetActiveState()->Draw();
			Debug::draw();
			Display::update();

			Display::pollEvents();
		}
	}
}