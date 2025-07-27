#pragma once
#include "Dino.h"
#include "Obstacle.h"

class Game {
private:
	sf::RenderWindow window;

	enum class State { StartScreen, Playing, GameOver };
	State gameState;

	//ui
	sf::Font font;
	sf::Text startScreenText, scoreText, gameOverText;

	//background
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

	//objects
	std::vector<Obstacle> obstacles;
	Dino dino;

	//logic parts
	int score = 0;
	void handleInput(const sf::Event& e);
	void update();
	void render();
	void reset();
	void loadAssets();
	void checkCollisions();
	
	void drawObstacles();
public:
	void run();
	Game();
	void getInput();
};