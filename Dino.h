#pragma once
#include <SFML/Graphics.hpp>

class Dino {
private:
	//different dino sprites depending ont he action needed
	sf::Sprite sprite;
	sf::Texture standingTexture;
	sf::Texture leftTexture;
	sf::Texture rightTexture;
	sf::Texture upTexture;
	sf::Texture acrossTexture;
	sf::Texture rollDowntexture;
	sf::Texture rollUpTexture;
	sf::Texture deadTexture;

	//change sprites
	enum class State { Standing, LeftStep, RightStep, Flipping, Rolling, Dead };
	State currentState = State::Standing;
	//jump phase sprites
	enum class JumpState { None, Up, Fly, RollDown, RollUp, Done };
	JumpState jumpPhase;

	float runTimer; //timer for running animation
	float runSwitchTime; //time betwen alternating legs

	float jumpTimer; //tine for jump animation
	float jumpDuration; //duration of the jump

	bool isJumping; //flag to check if dino is jumping

public:
	Dino();
	void load();
	void draw(sf::RenderWindow& window);
	void dead();
	void jump(float dt);
	void run();
	void update(float dt);
	void reset();
};