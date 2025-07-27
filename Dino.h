#pragma once
#include <SFML/Graphics.hpp>

class Dino {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f veolicty;
	bool isJumping = false;

public:
	Dino();
	void load();
	void update(float dt);
	void draw(sf::RenderWindow& window);
	sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }
};