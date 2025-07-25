#pragma once
#include "Dino.h"
#include "Obstacle.h"

class Game {
private:
	sf::RenderWindow window;
	Dino dino;
	std::vector<Obstacle> obstacles;
	sf::Font font;
	sf::Text gameOverText;
	enum class State {Playing, GameOver, Rules} gameState;
};