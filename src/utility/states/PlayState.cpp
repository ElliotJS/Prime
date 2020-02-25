#include <sstream>
#include <functional>
#include <iostream>

#include "PauseState.h"
#include "PlayState.h"

namespace Prime {
	PlayState::PlayState() : _scene()
	{
	}
	PlayState::PlayState(GameDataRef data) : _data(data), _scene() {
	}

	void PlayState::Init() {
		_data->assets.LoadTexture("Play Background", PLAY_BACKGROUND_FILEPATH);
		_background = sf::Sprite(this->_data->assets.GetTexture("Play Background"));
	}

	void PlayState::HandleInput() {
		if (_data->input.IsKeyPressed(KEY_ESCAPE)) {
			_data->machine.AddState(StateRef(new PauseState(_data)), false);
		}
	}

	void PlayState::Update(float dt) {
		_scene.Update(dt);
	}

	void PlayState::Draw() {
		Display::Camera::DrawSprite(_background);

		_scene.Draw();
	}
}