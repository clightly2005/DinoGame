#include "Game.h"
#include <iostream>
using std::cerr;
/*
	core logic for the game loop, state management and the UI for game over screen and start screen
*/

Game::Game() : window(sf::VideoMode(800, 600), "SFML Test"), gameState(State::StartScreen) {
    loadAssets();
}

void Game::run() {
    sf::Event e;
    while (window.isOpen()) {
        //handle input
        handleInput(e);
        if (e.type == sf::Event::Closed) {
            window.close();
        }
        //update logic based on state
        update();
        //draw based on state
        render();
    }
}

void Game::render() {
    window.clear(sf::Color(246, 243, 245));
    if (gameState == State::StartScreen) {
        window.draw(startScreenText);
    }
    if (gameState == State::Playing) {
        window.draw(backgroundSprite); //floor line and trees
        dino.draw(window);
        drawObstacles();
        window.draw(scoreText);
    }
    if (gameState == State::GameOver) {
        dino.draw(window); //frozen dino
        drawObstacles();
        window.draw(gameOverText);
    }
    window.display();
}

//responding to key pressed events
void Game::handleInput(const sf::Event& e) {
    if (gameState == State::StartScreen && e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter) {
        gameState = State::Playing;
    }
    if (gameState == State::Playing && e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Space) {
            dino.jump(1.2);
        }
    }
    if (gameState == State::GameOver && e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter) {
       dino.reset();
    }
}

void Game::update() {
    float dt = 0.1f;
    if (gameState == State::Playing) {
        dino.update(dt); //run or jump
		checkCollisions();//stop game
        //updateScore();//score 
    }
}
void Game::loadAssets() {
    //font load check
    if (!font.loadFromFile("assets/start.ttf")) {
        cerr << "Failed to load font.\n";
        return;
    }
    //start screen text
    startScreenText.setFont(font);
    startScreenText.setString("Welcome to Dino Runner!\nPress Enter to start.");
    startScreenText.setCharacterSize(24);
    startScreenText.setFillColor(sf::Color::Black);
    startScreenText.setPosition(100, 200);
    //score text
    scoreText.setFont(font);
    scoreText.setCharacterSize(18);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10);
    scoreText.setString("Score: 0");
    //gameover text
    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER.\nPress Enter to Restart");
    gameOverText.setCharacterSize(24);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setPosition(100, 250);

    if (!backgroundTexture.loadFromFile("assets/background.png")) {
        cerr << "Failed to load background.\n";
        return;
    }
    backgroundSprite.setTexture(backgroundTexture);
}



