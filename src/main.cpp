#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    auto window = sf::RenderWindow{ { 1000u, 1000u }, "GameOfLife" };
    window.setFramerateLimit(144);
    
    Game game(400, 400);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        sf::RectangleShape square(sf::Vector2f(25.f, 25.f));
        window.draw(square);

        window.display();
    }
}