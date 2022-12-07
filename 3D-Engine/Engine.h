#pragma once

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include "Settings.h"

using namespace sf;

enum WindowMode {FULLSCREEN, WINDOWED, CUSTOM};

class Engine {


private:
	static Engine* instance;
	Engine();
	virtual ~Engine();

	sf::Clock clock;
	float deltaTime;

	void init(int windowMode);

	void update();
	void render();


public:

	static Engine *getInstance();

	sf::RenderWindow* window;

	bool doFillColor;
	void run();
	float getDeltaTime();
};