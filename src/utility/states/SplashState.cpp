#include <sstream>

#include "SplashState.h"
#include "MainMenuState.h"

#include <iostream>

namespace Prime {

	SplashState::SplashState(GameDataRef data) : _data(data) {

	}

	void SplashState::Init() {
		_data->assets.LoadTexture("Splash State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);
		_background = sf::Sprite(this->_data->assets.GetTexture("Splash State Background"));
		_background = Display::Camera::ScaleSprite(_background);
	}

	void SplashState::HandleInput() {
	}

	void SplashState::Update(float dt) {
		if (_clock.getElapsedTime().asSeconds() > SPLASH_SCREEN_SHOW_TIME) {
			_data->machine.AddState(StateRef(new MainMenuState(_data)) , true);
		}
	}

	void SplashState::Draw() {
		Display::Camera::DrawSprite(_background);
	}

}