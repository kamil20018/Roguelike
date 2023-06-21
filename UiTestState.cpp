#include "UiTestState.h"

UiTestState::UiTestState(std::shared_ptr<Context>& context) : context(context) {

}

UiTestState::~UiTestState() {

}

void UiTestState::Init() {

}

void UiTestState::ProcessInput() {
	sf::Event event;
	while (_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			_window->close();
		}
		else if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::Escape:
					_states->PopCurrent();
					break;
			}
		}

	}
}

void UiTestState::Update() {

}

void UiTestState::Draw() {
	_window->clear(sf::Color(200, 0, 0));
	_window->display();
}

