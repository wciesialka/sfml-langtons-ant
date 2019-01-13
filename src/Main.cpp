#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "Cell.h"

Grid g;

void render(sf::RenderWindow* window)
{
    window->clear();

    for(int j = 0; j < GRID_HEIGHT; j++)
    {
        for(int i = 0; i < GRID_WIDTH; i++)
        {
            sf::RectangleShape space(sf::Vector2f(GRID_SIZE,GRID_SIZE));
            space.setPosition(i*GRID_SIZE,j*GRID_SIZE);
            if(g.getCell(i,j)->isWhite())
            {
                space.setFillColor(sf::Color::White);
            } else
            {
                space.setFillColor(sf::Color::Black);
            }
            window->draw(space);
        }
    }
}

int main(int argc, char** argv)
{
    g = Grid();
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT),"Langton's Ant");

    while(window.isOpen())
    {
        sf::Event ev;
        while(window.pollEvent(ev))
        {
            if(ev.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        render(&window);
        window.display();
    }

    return 0;
}