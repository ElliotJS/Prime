#include <sstream>
#include <functional>
#include <iostream>

#include "MainMenuState.h"
#include "PlayState.h"	
                      
namespace Prime {

	MainMenuState::MainMenuState(GameDataRef data) : _data(data), _menu(Menu::Menu(_data)) {
	}

	void MainMenuState::Play() {
		_data->machine.AddState(StateRef(new PlayState(_data)), true);
	}

	void MainMenuState::Options() {

	}

	void MainMenuState::Exit() {
		Display::close();
	}

	void MainMenuState::Init() {
		Button play = Button::Button(_data, "Play", VIEW_WIDTH * 0.5f, VIEW_HEIGHT * 0.6f, [this]() {Play();});
		Button options = Button::Button(_data, "Options", VIEW_WIDTH * 0.5f, VIEW_HEIGHT * 0.7f, [this]() {Options();});
		Button exit = Button::Button(_data, "Exit", VIEW_WIDTH * 0.5f, VIEW_HEIGHT * 0.8f, [this]() {Exit();});
		Button buttons[] = { play, options, exit };
		std::vector<Button> buttonVec(buttons, buttons + sizeof(buttons) / sizeof(Button));
		this->_menu._buttons = buttonVec;

		_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_background = sf::Sprite(this->_data->assets.GetTexture("Main Menu Background"));
	}

	void MainMenuState::HandleInput() {
		_menu.HandleInput();
	}

	void MainMenuState::Update(float dt) {
		_menu.Update(dt);
	}

	void MainMenuState::Draw() {
		Display::Camera::DrawSprite(_background);
		_menu.Draw();
	}

}