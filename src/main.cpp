#include <SFML/Graphics.hpp>
#include "game.h"

void drawGrid(sf::RenderWindow& win, int rows, int cols) {
    // initialize values
    int numLines = rows + cols - 2;
    sf::VertexArray grid(sf::Lines, 2 * (numLines));
    win.setView(win.getDefaultView());
    auto size = win.getView().getSize();
    float rowH = size.y / rows;
    float colW = size.x / cols;
    // row separators
    for (int i = 0; i < rows - 1; i++) {
        int r = i + 1;
        float rowY = rowH * r;
        grid[i * 2].position = { 0, rowY };
        grid[i * 2 + 1].position = { size.x, rowY };
    }
    // column separators
    for (int i = rows - 1; i < numLines; i++) {
        int c = i - rows + 2;
        float colX = colW * c;
        grid[i * 2].position = { colX, 0 };
        grid[i * 2 + 1].position = { colX, size.y };
    }
    // draw it
    win.draw(grid);
}

int main()
{
    sf::Clock Clock;
    const auto WHITE = sf::Color(255, 255, 255);
    const auto BLACK = sf::Color(0, 0, 0);
    const auto SQUARE_SIZE = 25;
    auto window = sf::RenderWindow{ { 1000u, 1000u }, "GameOfLife", sf::Style::Close };
    window.setFramerateLimit(144);
    int n{ 40 };
    int m{ 40 };
    Game game(n, m);

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
        sf::RectangleShape white_square(sf::Vector2f(23.f, 23.f));
        white_square.setFillColor(WHITE);
        white_square.setOutlineColor(WHITE);
        white_square.setOutlineThickness(1.f);

        drawGrid(window, n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (game.getCurrAlive(i, j)) {
                    white_square.setPosition(i * SQUARE_SIZE, j * SQUARE_SIZE);
                    window.draw(white_square);
                }
            }
        }

        window.display();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            int grid_x = static_cast<int>(localPosition.x / SQUARE_SIZE);
            int grid_y = static_cast<int>(localPosition.y / SQUARE_SIZE);
            game.setAlive(grid_x, grid_y);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            int grid_x = static_cast<int>(localPosition.x / SQUARE_SIZE);
            int grid_y = static_cast<int>(localPosition.y / SQUARE_SIZE);
            game.setDead(grid_x, grid_y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            game.update();
        }
    }
}