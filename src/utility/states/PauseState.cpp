#include <sstream>
#include <functional>
#include <iostream>

#include "PauseState.h"

namespace Prime {

	PauseState::PauseState(GameDataRef data) : _data(data), _menu(Menu::Menu(_data)) {
	}

	void PauseState::Play() {
		_data->machine.RemoveState();
	}

	void PauseState::Options() {

	}

	void PauseState::Exit() {
		Display::close();
	}

	void PauseState::Init() {
		Button resume = Button::Button(_data, "Resume", VIEW_WIDTH * 0.5f, VIEW_HEIGHT * 0.6f, [this]() {Play();});
		Button options = Button::Button(_data, "Options", VIEW_WIDTH * 0.5f, VIEW_HEIGHT * 0.7f, [this]() {Options();});
		Button exit = Button::Button(_data, "Exit", VIEW_WIDTH * 0.5f, VIEW_HEIGHT * 0.8f, [this]() {Exit();});
		Button buttons[] = { resume, options, exit };
		std::vector<Button> buttonVec(buttons, buttons + sizeof(buttons) / sizeof(Button));
		this->_menu._buttons = buttonVec;

		_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_background = sf::Sprite(this->_data->assets.GetTexture("Main Menu Background"));
	}

	void PauseState::HandleInput() {
		_menu.HandleInput();

		if (_data->input.IsKeyPressed(KEY_ESCAPE)) {
			Play();
		}
	}

	void PauseState::Update(float dt) {
		_menu.Update(dt);
	}

	void PauseState::Draw() {
		Display::Camera::DrawSprite(_background);
		_menu.Draw();
	}

}