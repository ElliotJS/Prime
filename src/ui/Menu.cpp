#include "Menu.h"
#include "../KEYS.h"
#include <iostream>

namespace Prime {
	Menu::Menu(GameDataRef data) : _data(data) {
		
	}

	void Menu::Draw() {
		for(auto & i : _buttons) {
			i.Draw();
		}
	}

	void Menu::HandleInput() {
		if (_data->input.IsKeyPressed(KEY_UP)) {
			MoveUp();
		}
		if (_data->input.IsKeyPressed(KEY_DOWN)) {
			MoveDown();
		}
		if (_data->input.IsKeyPressed(KEY_SELECT)) {
			int val = 0;
			for (auto& i : _buttons) {
				if (val == current) {
					i.action();
				}
				val += 1;
			}
		}
	}

	void Menu::Update(float dt) {
		UpdateSelected();
		int val = 0;
		for (auto& i : _buttons) {
			if (_data->input.IsMouseOver(i.GetBounds())) {
				this->current = val;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					i.action();
				}
			}
			val += 1;
		}
	}

	void Menu::MoveUp() {
		this->current -= 1;
		if (this->current < 0) {
			//this->current = 0;
			this->current = this->_buttons.size() - 1;
		}
	}

	void Menu::MoveDown() {
		this->current += 1;		
		if (this->current >= this->_buttons.size()) {
			//this->current = this->_buttons.size() - 1;
			this->current = 0;
		}		
	}

	void Menu::UpdateSelected() {
		int val = 0;
		for (auto& i : _buttons) {
			if (val == current)
				i.selected = true;
			else
				i.selected = false;

			val += 1;
		}
	}
}