#pragma once

class Obstacle {
private:
	sf::Sprite sprite;
	sf::Texture texture;

public:
	void load();
	void update(float dt);
	void draw(sf::RenderWindow& window);
	sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }
};