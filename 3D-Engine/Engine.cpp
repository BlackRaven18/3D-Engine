#include "Engine.h"

Engine* Engine::instance = nullptr;


Engine::Engine() {
	this->init(WINDOWED);
}

Engine::~Engine() {
	delete this->window;
}

Engine* Engine::getInstance() {
	if ( instance == nullptr) {
		instance = new Engine();
	}
	return instance;
}


void Engine::run() {
	clock = sf::Clock::Clock();
	sf::Time prevTime;
	sf::Time curTime;

	// Main Loop
	while (this->window->isOpen()) {
		prevTime = clock.getElapsedTime();;

		this->update();
		this->render();

		curTime = clock.getElapsedTime();
		this->deltaTime = curTime.asSeconds() - prevTime.asSeconds();
	}
}



//Private functions
void Engine::init(int windowMode) {
	Vector2f resolution;

	resolution.x = SCREEN_WIDTH_HD;
	resolution.y = SCREEN_HEIGHT_HD;


	switch (windowMode) {
	case FULLSCREEN:
		this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), APP_TITLE, Style::Fullscreen);
		break;
	case WINDOWED:
		this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), APP_TITLE, Style::Close);
		break;
	case CUSTOM:
		this->window = new RenderWindow(VideoMode(SCREEN_WIDTH_FHD, SCREEN_HEIGHT_FHD), APP_TITLE, Style::Close);
		break;
	}

	this->window->setVerticalSyncEnabled(true);
	this->window->setFramerateLimit(FPS_LIMIT);
}

void Engine::update() {
	Event event;

	


	while (this->window->pollEvent(event)) {

		switch (event.type)
		{
			// window closed
		case sf::Event::Closed:
			this->window->close();
			break;

			// key pressed
		case sf::Event::KeyPressed:
			if (event.Event::key.code == Keyboard::Escape) {
				this->window->close();
			}

			break;
		case sf::Event::KeyReleased:
			
			break;

		default:
			break;
		}
	}
}

void Engine::render() {
	this->window->clear(sf::Color::White);

	

	this->window->display();
}