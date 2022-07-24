#include "UiTestState.h"

UiTestState::UiTestState(std::shared_ptr<Context>& context) : context(context) {



	std::string test = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi elementum mattis neque, eu pharetra nibh aliquet ut. Suspendisse molestie dui in elit pellentesque laoreet. Nam mi est, cursus vel lacus nec, pulvinar dapibus diam. Aenean nec neque dolor. Vivamus a tristique lorem. Proin vel mi vel lacus rhoncus tincidunt. Curabitur ut mauris cursus, placerat mauris at, tincidunt est. Sed a dignissim erat, at consequat sapien. Aliquam erat volutpat. Integer fermentum augue vitae tortor viverra, eu vehicula turpis ullamcorper. Fusce erat libero, pharetra in diam eget, sollicitudin malesuada mauris. Suspendisse potenti. Donec urna justo, semper volutpat risus faucibus, hendrerit ultrices mauris. Nulla tellus ante, condimentum suscipit nulla ut, placerat porta ligula. Quisque malesuada, nisi eu iaculis convallis, dui ex porta lorem, quis fringilla enim massa quis enim. Donec consectetur id mi nec feugiat. Vestibulum porttitor elit ut lacus facilisis, et dictum purus viverra.Interdum et malesuada fames ac ante ipsum primis in faucibus. Mauris tincidunt odio ac lobortis lobortis. Aenean tempor enim ligula, sit amet vulputate odio interdum a. Etiam non lectus nec orci feugiat venenatis at eu ipsum.";


	TextField2 test2(test);


	field = TextField(test, sf::Vector2f(10, 10), context->assets->GetFont("pixel_font"), false);
	field.setPadding(20);
	field.setScalingBoundsSize(sf::Vector2f(21.2f, 21.2f));
	//_assets->AddTexture("hero", "Resources/Textures/Hero/Hero.png");
	//this->hero = std::make_unique<Hero>(_assets->GetTexture("hero"));
	//this->w = 300;
	//this->h = 300;
	//this->counter = 0;
}

UiTestState::~UiTestState() {
}

void UiTestState::Init() {
	//for (int i = 0; i < h; i++) {
	//	for (int j = 0; j < w; j++) {
	//		pairs[i][j] = { noise.perl(0.01f * (i + 1), 0.01f * (j + 1)) };
	//	}
	//}
	//noise.getGradVals(sf::Vector2i(0, 0));
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
	//this->counter++;
}

void UiTestState::Draw() {



	//draw perlin noise
	//float rectSize = 2.0f;
	//if (counter < 10) {
	//	_window->clear(sf::Color(200, 0, 0));
	//	sf::RectangleShape rectangle;
	//	rectangle.setSize(sf::Vector2f(rectSize, rectSize));
	//	for (int i = 0; i < h; i++) {
	//		for (int j = 0; j < w; j++) {
	//			rectangle.setPosition(sf::Vector2f(i * rectSize, j * rectSize));
	//			float val = pairs[i][j] + 1;
	//			sf::Uint8 rgb = (sf::Uint8)255.0f / 2.0f * val;
	//			rectangle.setFillColor(sf::Color(rgb, rgb, rgb));
	//			rectangle.setOutlineColor(sf::Color::Red);
	//			rectangle.setOutlineThickness(0);
	//			_window->draw(rectangle);
	//		}
	//	}
	//}

	_window->clear(sf::Color(200, 0, 0));
	_window->draw(field);
	_window->display();
}

