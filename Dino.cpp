/*
	handle dino animation, jumping, collisions and the actual dino player
*/
#include "Dino.h"
#include <iostream>
#include "Game.h"

Dino::Dino() {
	currentState = State::Standing;
	jumpPhase = JumpState::None;
	isJumping = false;
	jumpTimer = 0.0f;
	runTimer = 0.0f;
	load();
}

void Dino::load() {
	if (!standingTexture.loadFromFile("assets/dino.png")) {
		std::cerr << "Error loading dino standing texture" << std::endl;
	}
	if (!upTexture.loadFromFile("assets/dinoUp.png")) {
		std::cerr << "Error loading dino standing texture" << std::endl;
	}
	if (!acrossTexture.loadFromFile("assets/dinoAcross.png")) {
		std::cerr << "Error loading dino stan ding texture" << std::endl;
	}
	if (!rollDowntexture.loadFromFile("assets/dinoRollDown.png")) {
		std::cerr << "Error loading dino stan ding texture" << std::endl;
	}
	if (!rollUpTexture.loadFromFile("assets/dinoRollUp.png")) {
		std::cerr << "Error loading dino stan ding texture" << std::endl;
	}
	if (!leftTexture.loadFromFile("assets/dinoLeft.png")) {
		std::cerr << "Error loading dino standing texture" << std::endl;
	}
	if (!rightTexture.loadFromFile("assets/dinoRight.png")) {
		std::cerr << "Error loading dino standing texture" << std::endl;
	}
	
	if (!deadTexture.loadFromFile("assets/dino.png")) {
		std::cerr << "Error loading dino standing texture" << std::endl;
	}

	sprite.setTexture(standingTexture);//start position
	sprite.setPosition(100, 400);
}

void Dino::dead() {
	currentState = State::Dead;
	sprite.setTexture(deadTexture);
}
void Dino::jump(float dt) {
	if (!isJumping) {
		isJumping = true;
		jumpTimer = 0.0f;//reset jump timer
		jumpPhase = JumpState::Up;
	}

	jumpTimer += dt;
	float jumpProgress = jumpTimer / jumpDuration;
	float yOffset = 0.0f;

	if (jumpProgress < 0.2f) {
		jumpPhase = JumpState::Up; 
		sprite.setTexture(upTexture); //sprite for up phase
		yOffset = -60.0f;//move up by 60 pixels
	}
	else if (jumpProgress < 0.4f){
		jumpPhase = JumpState::Fly;
		sprite.setTexture(acrossTexture); //sprite for up phase
		yOffset = -100.0f;
	}
	else if (jumpProgress < 0.6f) {
		jumpPhase = JumpState::RollDown;
		sprite.setTexture(rollDowntexture); 
		yOffset = -80.0f;
	}
	else if (jumpProgress < 0.8f) {
		jumpPhase = JumpState::RollUp;
		sprite.setTexture(rollUpTexture);
		yOffset = -100.0f;
	}
	else{
		jumpPhase == JumpState::Done;
		sprite.setTexture(standingTexture);
	}

	sprite.setPosition(sprite.getPosition().x, 400 + yOffset);

	if (jumpProgress >= 1.0f) {
		isJumping = false;
		jumpPhase = JumpState::None;
		sprite.setPosition(sprite.getPosition().x, 400);
	}
}

void Dino::run() {
	if (currentState == State::LeftStep) {
		runTimer += runSwitchTime;
		if (runTimer >= runSwitchTime) { 
			currentState = State::RightStep;//switches to right step when exceeds switch time
			sprite.setTexture(rightTexture);
			runTimer = 0.0f;
		}
	}
	else if (currentState == State::RightStep) {
		runTimer += runSwitchTime; 
		if (runTimer >= runSwitchTime) {
			currentState = State::LeftStep;//switch to left step
			sprite.setTexture(leftTexture);
			runTimer = 0.0f;
		}
	}
}

void Dino::update(float dt){
	if (isJumping) {
		jump(dt);
	}
	else {
		run();
	}
}

void Dino::reset() {
	currentState = State::Standing;
	sprite.setTexture(standingTexture);
	sprite.setPosition(100, 400);
	isJumping = false;
	jumpTimer = 0.0f;
	runTimer = 0.0f;
}