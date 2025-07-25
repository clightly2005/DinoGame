#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
    //game loop
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color{ 246, 243, 245 });
        Game game;
        game.run();

        window.display();
    }

    return 0;
}
